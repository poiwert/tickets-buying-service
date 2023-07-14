// Глобальна змінна
int film_name;

int film_catalog() {        
    int buy_tickets_menu_section, info, return_function;
        printf("\tChoose a film \n");
        printf("\tMission impossible: Reckoning. Part One (1\n");
        printf("\tOppenheimer (2)\n");
        printf("\tBarby (3)\n");
        printf("\tExit (0)\n");
        scanf("%d", &buy_tickets_menu_section);
        
        switch (buy_tickets_menu_section) {
            case 1:
                printf("You have chosen: Mission impossible: Reckoning. Part One\n");
                film_name = 1;
                info=film_info(film_name);
                break;
            case 2:
                printf("You have chosen: Oppenheimer\n");
                film_name = 2;
                info=film_info(film_name);
                break;
            case 3:
                printf("You have chosen: Barby\n");
                film_name = 3;
                info=film_info(film_name);
                break;
            case 0:
                printf("Exit to main menu\n");
                return_function = main();
                break; 
            default:
                printf("Input another key\n");
                break;
        }
}