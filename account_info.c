int account_info() {
    int account_info_menu_section;
        while (1) {
        printf("(Enter '0' to go back to the main menu)\n"); 
        printf("--Pick info that you want to see--\n");
        printf("| Description(1) Active session(2) |\n");
        scanf("%d", &account_info_menu_section);
        
        switch (account_info_menu_section) {
            case 0:
                printf("Exit to main menu");
                return 0;
                break;
            case 1:
                description_function();
                break;
            case 2:
                active_session();
                break;
            default:
                printf("Input another key\n");
                break;
        }
    }
}
