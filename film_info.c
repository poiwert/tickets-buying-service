
    void cinema_info(struct Movie movie) {
        while(1){
        printf("__________________________________________________________\n");
        printf("Film Name: %s\n", movie.name);
        printf("__________________________________________________________\n");
        printf("Description: %s\n", movie.description);
        printf("__________________________________________________________\n");

        int buy_tickets_choice;
        printf("Would you like to buy tickets for this film? (1 - Yes, 0 - No): ");
        scanf("%d", &buy_tickets_choice);
        if (buy_tickets_choice == 1) {
            purchasing_function();
        }
        if(buy_tickets_choice == 0){
            return;
        }
            else{
            printf("Input another key\n");
        }
        printf("__________________________________________________________\n");
    }
}
