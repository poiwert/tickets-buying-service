int account_info(struct Movie movie) {
    int account_info_menu_section;
    struct ActiveSession* active_session = malloc(sizeof(struct ActiveSession));
    strcpy(active_session->movie_name, movie.name); 
    active_session->date = date_session;
    active_session->time = session_time;
    active_session->row = row;
    active_session->seat = seat;
    active_session->film_localization_id = film_localization_id;
    struct DateTime* dt = malloc(sizeof(struct DateTime));
    while (1) {
        printf("(Enter '0' to go back to the main menu)\n");
        printf("--Pick info that you want to see--\n");
        printf("| Description(1) Active session(2) History(3) |\n");
        scanf("%d", &account_info_menu_section);

        switch (account_info_menu_section) {
            case 0:
                printf("Exit to main menu");
                free(active_session);
                main(movie);
                free(dt);
                free(active_session);
                break;
            case 1:
                description_function(movie);
                free(dt);
                free(active_session);
                break;
            case 2:
                active_session_function(active_session, dt);
                free(dt);
                free(active_session);
                break;
            case 3:
                show_history();
                free(dt);
                free(active_session);
                break;
            default:
                printf("Input another key\n");
                break;
        }
    }
}
