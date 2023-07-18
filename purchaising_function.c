#include <time.h>

int quantity_of_tickets = 0,money_spended_summary = 0, date_session = 0,session_time,money_spended,row,seat, amount_of_booked_seats=0, film_localization_id,popcorn_menu, buy_tickets_menu_section,popcorn_store_entry;;

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

void date_selection_function(struct DateTime* dt, struct Movie movie){
    int month_end_day;
    start: // Label for restarting the cycle
    while(1){
        printf("Current date: %d-%02d-%02d\n", dt->day, dt->month, dt->year);
        if (dt->month%2)
        {
            month_end_day=30;
        }
        if (dt->month==2)
        {
            month_end_day=28;
        }
        else
        {
            month_end_day=31;
        }
        if(dt->year==2024||dt->year==2028||dt->year==2032)
        {
            if (dt->month==2)
            {
                month_end_day=29;
            }
        }
    
        printf("Input a day in this month, when you want to go to the cinema\n");
        printf("You can pick from %d to %d\n",dt->day,month_end_day);
        printf("(or press '0' if you want to pick other film)\n");
        scanf("%d", &date_session);
        if (date_session==0)
        {
            film_catalog(movie);
        }
        
        if (date_session<dt->day||date_session>month_end_day)
        {
            printf("__________________________________________\n");
            printf("\tChoose another date\n");
            printf("__________________________________________\n");
            goto start; // Go to the beginning of the cycle
        }
        if (date_session==dt->day)
        {
            if (dt->hour>=20)
            {
                printf("We have no more tickets for today\n");
            }
            else
            {
                printf("Chosen day is - %d\n",date_session);
                return;
            }
            
        }
        else
        {
            printf("Chosen day is - %d\n",date_session);
            return;
        }
    }
}

void current_date_and_time_calculate(struct DateTime* dt){
    time_t currentTime;
    struct tm *localTime;

    // Get the current time
    currentTime = time(NULL);

    // Convert to local time
    localTime = localtime(&currentTime);

    // Get the date value
    dt->year = localTime->tm_year + 1900;  // Add 1900 because struct tm stores the year starting from 1900
    dt->month = localTime->tm_mon + 1;     // Add 1 because struct tm stores months starting from 0
    dt->day = localTime->tm_mday;
    
    // Get the time value
    dt->hour = localTime->tm_hour;
    dt->minute = localTime->tm_min;
}

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

int purchasing_function(struct Movie movie) {
    int purchasing_function_menu_section;
    struct ActiveSession* active_session = malloc(sizeof(struct ActiveSession));
    strcpy(active_session->active_session_movie_name, movie.name); 
    active_session->active_session_date = date_session;
    active_session->active_session_time = session_time;
    active_session->active_session_row = row;
    active_session->active_session_seat = seat;
    active_session->active_session_film_localization_id = film_localization_id;
    struct DateTime* dt = malloc(sizeof(struct DateTime));
    purchasing_function_display_menu();
        while (1)
    {
        money_spended=0;
        current_date_and_time_calculate(dt);
        date_selection_function(dt,movie);
        purchasing_function_display_menu();
        scanf("%d", &purchasing_function_menu_section);
        switch (purchasing_function_menu_section)
        {
        case 1: session_time=10; money_spended=120; today_time_check(dt,movie); seat_and_row_selection(dt,active_session,movie); free(dt); free(active_session); break;
        case 2: session_time=12; money_spended=140; today_time_check(dt,movie); seat_and_row_selection(dt,active_session,movie); free(dt); free(active_session); break;
        case 3: session_time=16; money_spended=160; today_time_check(dt,movie); seat_and_row_selection(dt,active_session,movie); free(dt); free(active_session); break;
        case 4: session_time=18; money_spended=180; today_time_check(dt,movie); seat_and_row_selection(dt,active_session,movie); free(dt); free(active_session); break;
        case 5: session_time=20; money_spended=180; today_time_check(dt,movie); seat_and_row_selection(dt,active_session,movie); free(dt); free(active_session); break;
        case 0: free(dt); free(active_session); film_catalog(movie); break;    
        default: printf("Invalid input\n");
        }
    }
}