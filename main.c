#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

#include "constants.h"
#include "enums.h"

#include "dialogue.h"
#include "heroine.h"
#include "event.h"




//clrscr function

void clear() {
    printf("\033[H\033[J");
}

//randomizer functions

//randomizes up to an excluded number
int random_up_to(int value) {
    return rand() % value;

}

//enum functions



//event functions


void converse(Heroine* heroine, int dialogue_index) {
    heroine->intimacy = heroine->intimacy + use_dialogue(heroine, heroine->dialogue_list[dialogue_index]);
    printf("(press any character to continue)");
    getch();
    clear();
}

void event_handler(Event* event) {
    if (strcmp(event->heroine->name, "Andre") == 0) {

        converse(event->heroine, 0);
        //collab

    }

}


int game() {

    int days; 

    days = 1;

    Event* event = initialize_events();
    Heroine* heroine_list = initialize_heroines();


    while (1==1) {

        if (event == NULL) {
            printf("<error>: events not connected\n");
            return days;
        }

        //randomize both the place and the heroine
        event->place = random_up_to(PLACE_AMT);
        event->heroine = &heroine_list[random_up_to(HEROINE_AMT)];

        char place[MIN_STRLEN];
        get_str_from_place(event->place, place);
        printf("TIME: %s\nPLACE: %s\n", event->name, place);
        event_handler(event);

        if (event->heroine->intimacy >= 100) {
            return days;
        }

        event = event->next;
        days++;
    }


}

int main(){

    srand(time(NULL));

    int days = game();

    printf("congratulations, you have completed the game in %d days.", days);

    return 0;

}
