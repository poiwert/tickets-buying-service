

void check_duplicate_tickets(){
    
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
