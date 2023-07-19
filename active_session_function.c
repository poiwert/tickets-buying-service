int calculate_expired_session(){
    
}

int active_session_function(struct ActiveSession* active_session, struct DateTime* dt){
    
    if (quantity_of_tickets==0){
        printf("You have no active sessions\n");
    }

    else{

        printf("Name: %s\n",active_session->movie_name);
        printf("Time: %d:00\n",active_session->time);
        printf("Date: %d-%02d-%02d\n",active_session->date, dt->month, dt->year);
        printf("Row: %d\n",active_session->row);
        printf("Seat: %d\n",active_session->seat);
        printf("Localization: %s\n", ((active_session->film_localization_id == 0) ? "Ukrainian" : "English"));
        calculate_expired_session(active_session,dt);
        free(dt);
    }
    
}