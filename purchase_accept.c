#include "qrcodegen.h" 
#include "stb_image_write.h" 
#include <qrcodegen.h> 

#define const char* history_filename="History.txt"
#define CODE_LENGTH 10

void generateQRCode(const char* data, const char* filename, int size){

     // Error correction level for the QR code
    enum qrcodegen_Ecc errCorLvl = qrcodegen_Ecc_LOW;

    // QR code buffers
    uint8_t qrcode[qrcodegen_BUFFER_LEN_MAX];
    uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];

    // Generate the QR code
    bool ok = qrcodegen_encodeText(data, tempBuffer, qrcode, errCorLvl, qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, qrcodegen_Mask_AUTO, true);
    if (!ok) {
        printf("QR code generation error\n");
        return;
    }

    // Allocate memory for the image buffer
    uint8_t* imageBuffer = (uint8_t*)malloc(size * size * 3);
    memset(imageBuffer, 255, size * size * 3); // Set the buffer to white color (255)

    int r, g, b;
    do {
        r = rand() % 100; // Generate a random value for the red channel (0-100) (255 max = white)
        g = rand() % 100; // Generate a random value for the green channel (0-100) (255 max = white)
        b = rand() % 100; // Generate a random value for the blue channel (0-100) (255 max = white)
    } while (r != g && r != b && g != b); // Check if all color channels are not equal

    // Fill the image buffer with the QR code pattern
    for (int y = 0; y < qrcodegen_getSize(qrcode) + 4; ++y) {
        for (int x = 0; x < qrcodegen_getSize(qrcode) + 4; ++x) {
            bool module = qrcodegen_getModule(qrcode, x - 2, y - 2);
            uint8_t color = module ? 0 : 150; // Set black (0) for QR code modules and grey (150) (255 max = white) for the background
            int offset = (y * size + x) * 3;
            imageBuffer[offset] = module ? r : color; // R
            imageBuffer[offset + 1] = module ? g : color; // G
            imageBuffer[offset + 2] = module ? b : color; // B
        }
    }

    // Write the image buffer to a JPEG file
    int success = stbi_write_jpg(filename, size, size, 3, imageBuffer, 10000);
    free(imageBuffer);

    if (!success) {
        printf("Failed to save the QR code image\n");
        return;
    }

    printf("Your QR code is saved in the file %s.\n", filename);

}

void generate_unique_code(char* code, int length){

    // List of characters from which the code will be generated
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    // Calculate the number of characters in the list
    int numCharacters = sizeof(characters) - 1;

    // Generate the unique code by randomly selecting characters from the list
    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % numCharacters;
        code[i] = characters[randomIndex];
    }

    // Null-terminate the code to make it a valid C-style string
    code[length] = '\0';

}

int history_add_info(struct DateTime* dt, struct ActiveSession* active_session, struct Movie movie,char code[]){

    FILE *file = fopen(history_filename, "a");

    if (file == NULL)
    {
        printf("File open error\n");
        return;
    }

    fprintf(file, "\nYour ticket code: %s\n\n Name: %s\n Date: %d-%02d-%02d\n Time: %d:00\n Row: %d\n Seat: %d\n Localization: %s\n\n\n\n_______________________________________\n", 
     code,active_session->movie_name, 
     active_session->date,
     dt->month, dt->year,
     active_session->time,
     active_session->row,
     active_session->seat,
     ((active_session->film_localization_id == 0) ? "Ukrainian" : "English"));
    fclose(file);
    return;
}

void ticket_creator(struct DateTime* dt, struct ActiveSession* active_session, struct Movie movie){

    // Initialize the random number generator using the current time as a seed
    srand(time(NULL));

    char code[CODE_LENGTH + 1];
    generate_unique_code(code, CODE_LENGTH);

    char filename[20];
    snprintf(filename, sizeof(filename), "ticket%d.txt", quantity_of_tickets);

    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("File open error\n");
        return;
    }

    fprintf(file, "Your ticket unique code: %s\n\n Name: %s\n Time: %d:00\n Date: %d-%02d-%02d\n Row: %d\n Seat: %d\n Localization: %s\n",
    code,
    active_session->movie_name, 
    active_session->time,
    active_session->date,
    dt->month, dt->year,
    active_session->row,
    active_session->seat,
    ((active_session->film_localization_id == 0) ? "Ukrainian" : "English"));
    fclose(file);

    printf("Your ticket is on your device (%s)\n", filename);

    history_add_info(dt, active_session, movie, code);

    // Generate a QR code for the ticket
    char qrFilename[20];
    snprintf(qrFilename, sizeof(qrFilename), "qrcode%d.png", quantity_of_tickets);
    generateQRCode(code, qrFilename, 25);
    film_catalog(movie);
    
}

void check_duplicate_tickets(struct DateTime* dt, struct ActiveSession* active_session, struct Movie movie){

    FILE* file = fopen(history_filename, "ab+");

    if (file == NULL) {

        file = fopen(history_filename, "wb");

        if (file == NULL) {
            printf("File creation error\n");
        }

        fclose(file);
        purchase_accept(dt, active_session, movie);
    }
    
    char line[256];
    char localization_from_history[100];
    int film_id_from_history;
    int date_from_history;
    int time_from_history;
    int row_from_history;
    int seat_from_history;
    int film_localization_id_from_history;
    char name_from_history[100] = ""; 

    while (fgets(line, sizeof(line), file)) {

        // Extract the ticket data from each line in the history file
        sscanf(line, " Name: %[^\n]", name_from_history);
        sscanf(line, " Date: %d", &date_from_history);
        sscanf(line, " Time: %d", &time_from_history);
        sscanf(line, " Row: %d", &row_from_history);
        sscanf(line, " Seat: %d", &seat_from_history);
        sscanf(line, " Localization: %s", localization_from_history);

        if (strcmp(localization_from_history, "Ukrainian") == 0) {
            film_localization_id_from_history = 0;
        } else if (strcmp(localization_from_history, "English") == 0) {
            film_localization_id_from_history = 1;
        }
        
        if (strncmp(name_from_history, "Mission impossible: Reckoning. Part One\0", 39) == 0) {
            film_id_from_history = 1; 
        } else if (strncmp(name_from_history, "Oppenheimer\0",11) == 0) {
            film_id_from_history = 2; 
        } else if (strncmp(name_from_history, "Barby\0",5) == 0) {
            film_id_from_history = 3; 
        }
    }

        // Compare the extracted data with the data of the current ticket
        if (film_id_from_history == buy_tickets_menu_section &&
        date_from_history == date_session &&
        time_from_history == session_time &&
        row_from_history == row &&
        seat_from_history == seat &&
        film_localization_id_from_history == film_localization_id) {
            printf("Duplicate ticket found. Change ticket data\n");
            fclose(file);
            purchasing_function(movie);
        }

    fclose(file);
    return;

}

int purchase_accept(struct DateTime* dt, struct ActiveSession* active_session, struct Movie movie){

    check_duplicate_tickets(dt,active_session,movie);

    int purchase_confirm;

    printf("Movie name: %s\n", movie.name); 
    printf("Date session: %d-%02d-%02d\n",date_session,dt->month,dt->year);
    printf("Session time: %d:00\n",session_time);
    printf("Seat: %d\n",seat);
    printf("Row: %d\n",row);
    printf("Localization: %s\n", (film_localization_id == 0) ? "Ukrainian" : "English");

    if(popcorn_store_entry==1){
        printf("You spent %d UAH in popcorn store\n",popcorn_menu);
    }

    printf("Cost: %d UAH\n", money_spended);

    while (1){

        printf("Confirm purchase? Yes(1), No(0): ");
        scanf("%d",&purchase_confirm);

        if (purchase_confirm==1){

            strcpy(active_session->movie_name, movie.name); 
            active_session->date = date_session;
            active_session->time = session_time;
            active_session->row = row;
            active_session->seat = seat;
            active_session->film_localization_id = film_localization_id;
            money_spended_summary+=money_spended;
            quantity_of_tickets++;
            printf("Purchase complete! Now you can check it in acctive session\n");
            ticket_creator(dt,active_session,movie);
            break;

        }

        if (purchase_confirm==0){

            printf("Purchaising denied!\n");
            film_catalog(movie);
            break;

        }

        else printf("Invalid input\n"); 

    }

}
