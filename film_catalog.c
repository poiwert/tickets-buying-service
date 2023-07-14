int film_catalog() {        
    int buy_tickets_menu_section, purchase, return_function;
        printf("\tChoose a film \n");
        printf("\tMission impossible: Reckoning. Part One (1) \n");
        printf("\tOppenheimer (2)  \n");
        printf("\tHeroes of the golden masks (3)  \n");
        printf("\tExit (0)\n");
        scanf("%d", &buy_tickets_menu_section);
        
        switch (buy_tickets_menu_section) {
            case 1:
                printf("You have chosen: Kyky kaka\n");
                
                break;
            case 2:
                printf("You have chosen: Topol\n");
                
                break;
            case 3:
                printf("You have chosen: RTR\n");

                break;
            case 0:
                printf("Exit to film catalog\n");
                return_function = main();
                break; 
            default:
                printf("Input another key\n");
                break;
        }
}