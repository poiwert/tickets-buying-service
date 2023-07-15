
struct Movie {
    char name[100];
    char description[1000];
};

void display_film_catalog() {
    printf("__________________________________\n");
    printf("\t|               |\n");
    printf("\t| Choose a film |\n");
    printf("\t|               |\n");
    printf("__________________________________\n");
    printf("| Mission impossible: Reckoning. Part One (1)   \n");
    printf("__________________________________\n");
    printf("| Oppenheimer (2)  |\n");
    printf("__________________________________\n");
    printf("| Barby (3)   \n");
    printf("__________________________________\n");
    printf("\t  Exit (0)\n");
}

int film_catalog() {        

    int buy_tickets_menu_section;
    struct Movie movies[3]; 

    strcpy(movies[0].name, "Mission impossible: Reckoning. Part One");
    strcpy(movies[0].description, "IMF agent Ethan Hunt's new mission is to retrieve half of a key from his ally Ilsa Faust, on whom IMF has placed a bounty. He travels to the Empty Quarter in the Arabian Desert, briefly reunites with Ilsa and tells her to lay low. Back in the US, Ethan infiltrates a meeting of the Community, where officials of various intelligence agencies, including former IMF director Eugene Kittridge and DNI Denlinger, discuss an experimental AI called the Entity. Originally designed to sabotage digital systems, the Entity went rogue, expanded to potential sentience, and infiltrated all major defense and military systems and intelligence networks. Major powers are racing both to prevent sabotage and to gain control of the Entity.");

    strcpy(movies[1].name, "Oppenheimer");
    strcpy(movies[1].description, "The film's screenplay is based on the book 'American Prometheus: The Triumph and Tragedy of J. Robert Oppenheimer' written by Kai Bird and Martin Sherwin, which received the Pulitzer Prize for Biography or Autobiography. The main character is an American physicist who, under his leadership, developed the atomic bomb during World War II.");

    strcpy(movies[2].name, "Barby");
    strcpy(movies[2].description, "Family comedy, telling the story of the world's most famous doll - what if Barbie were a real girl living among us? Too imperfect for the perfect world of Barbiedom, she ends up being banished and encounters the harsh reality of the human world.");

    while(1){
        display_film_catalog();
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
}