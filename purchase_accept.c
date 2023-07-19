const char* history_filename="History.txt";

void ticket_creator(){
    
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
            film_catalog(movie);
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
