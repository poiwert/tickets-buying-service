int account_info() {
        while (1) {
        printf("(Enter '0' to go back to the main menu)\n");
        int account_info_menu_section, return_function, desc;
        printf("Pick info that you want to see\n");
        printf("Description(1) Active session(2)\n");
        scanf("%d", &account_info_menu_section);
        
        switch (account_info_menu_section) {
            case 0:
                printf("Exit to main menu");
                return_function = main();
                break;
            case 1:
                desc = description_function();
                break;
            case 2:
                printf("Active session\n");
                break;
            default:
                printf("Input another key\n");
                break;
        }
    }
}