
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

    strcpy(movies[0].name, "Mission impossible: Reckoning. Part One\0");
    strcpy(movies[0].description, "Age: 16+\n
                                   Director: Christopher McQuarrie (Mission: Impossible: Fallout, Mission: Impossible: Rogue Nation, Jack Reacher)\n
                                   Genre: Adventure, Action\n
                                   Cast: Tom Cruise (Mission: Impossible franchise), Pom Klementiev (Guardians of the Galaxy 2 franchise), Hayley Atwell (Agent Carter series), Vanessa Kirby (Fast and Furious: Hobbs and Shaw), Rebecca Ferguson (Mission: Impossible: Rogue Nation)\n
                                   Description: Ethan Hunt and the IMF team must track down a terrifying new weapon that threatens all of humanity if it falls into the wrong hands. With control of the future and the fate of the world at stake, a deadly race around the globe begins\n");

    strcpy(movies[1].name, "Oppenheimer\0");
    strcpy(movies[1].description, "Age: 16+\n
                                   Director: Christopher Nolan (Inception, Dunkirk, The Shawshank Redemption, Interstellar)\n
                                   Genre: Historical, Based on real events\n
                                   Cast: Cillian Murphy (TV series 'Pointy Hats', 'Inception'), Emily Blunt (A Quiet Place dilogy), Robert Downey Jr. (Iron Man), Florence Pugh (Little Women, Black Widow), Matt Damon (The Outsiders, Ocean's Eleven)\n
                                   Description: It is based on the 2005 biography American Prometheus by Kai Bird and Martin J. Sherwin about J. Robert Oppenheimer, a theoretical physicist who was pivotal in developing the first nuclear weapons as part of the Manhattan Project and thereby ushering in the Atomic Age\n");
   
    strcpy(movies[2].name, "Barby\0");
    strcpy(movies[2].description, "Age: 12+\n
                                   Director: Greta Gerwig (Little Women, Lady Bird)\n
                                   Genre: Adventure, Comedy, Romance\n
                                   Cast: Margot Robbie (Birds of Prey and The Fantastic Harley Quinn, Once Upon a Time in Hollywood, Babel), Ryan Gosling (Blade Runner 2049, La La Land), Kate McKinnon, Ariana Greenblatt, Michael Cera and others\n
                                   Description: Barbie meets with Weird Barbie, an outcast in Barbieland, who tells her she and everyone who lives in Barbieland is actually a doll. In order to recover from her mysterious affliction, Barbie must travel into the 'Real World' and find Sasha, the girl who owns her\n");    while (1) {
        
        display_film_catalog();
        scanf("%d", &buy_tickets_menu_section);

        if (buy_tickets_menu_section >= 1 && buy_tickets_menu_section <= 3) {
            printf("You have chosen: %s\n", movies[buy_tickets_menu_section - 1].name);
            cinema_info(movies[buy_tickets_menu_section - 1]);
        } else if (buy_tickets_menu_section == 0) {
            printf("Exiting to the main menu\n");
            return;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}
