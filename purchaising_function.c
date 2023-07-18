
struct Movie {
    char name[100];
    char description[1000];
};

struct DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
};

struct ActiveSession {
    char active_session_movie_name[100];
    int active_session_date;
    int active_session_time;
    int active_session_row;
    int active_session_seat;
    int active_session_film_localization_id;
};

void purchasing_function_display_menu(){
        printf("__________________________________\n");
        printf("\t  |               |\n");
        printf("\t  | Choose a time |\n");
        printf("\t  |               |\n");
        printf("__________________________________\n");
        printf("\t| 10:00, 120 UAH (1) |\n");
        printf("__________________________________\n");
        printf("\t| 12:00, 140 UAH (2) |\n");
        printf("__________________________________\n");
        printf("\t| 16:00, 160 UAH (3) |\n");
        printf("__________________________________\n");
        printf("\t| 18:00, 180 UAH (4) |\n");
        printf("__________________________________\n");
        printf("\t| 20:00, 180 UAH (5) |\n");
        printf("__________________________________\n");
        printf("\t      Exit (0)\n");
} 

int purchasing_function() {
    purchasing_function_display_menu();
}