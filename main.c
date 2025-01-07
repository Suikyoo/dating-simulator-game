#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#include "constants.h"
#include "enums.h"

#include "dialogue.h"
#include "heroine.h"
#include "event.h"





//randomizer functions

//randomizes up to an excluded number
int random_up_to(int value) {
    return rand() % value;
}

void activate_dialogue(Heroine* heroine, int dialogue_index, char* header_str) {
    printf("%d", heroine->intimacy);
    printf("\n");
    heroine->intimacy = heroine->intimacy + use_dialogue(heroine, heroine->dialogue_list[dialogue_index], header_str);
    printf("(press any character to continue)");
    getch();
}

void event_handler(Event* event, char* header_str) {
    if (strcmp(event->heroine->name, "Mio") == 0) {
        switch (event->heroine->intimacy){
            //kada case is condition ni sa intimacy
            //i.e. case 0 -> if (intimacy == 0)

            case 0:
                switch (event->place) {
                    case SCHOOL:
                        activate_dialogue(event->heroine, 15, header_str);
                        break;
                        
                    case CAFETERIA:
                        activate_dialogue(event->heroine, 16, header_str);
                        break;

                    case PARK:
                        activate_dialogue(event->heroine, 17, header_str);
                        break;
                }
                break;
            case 20:
               switch (event->place) {
                    case SCHOOL:
                        activate_dialogue(event->heroine, 0, header_str);
                        break;
                        
                    case CAFETERIA:
                        activate_dialogue(event->heroine, 1, header_str);
                        break;

                    case PARK:
                        activate_dialogue(event->heroine, 2, header_str);
                        break;
                } 
                break;

            case 40:
               switch (event->place) {
                    case SCHOOL:
                        activate_dialogue(event->heroine, 3, header_str);
                        break;
                        
                    case PARK:
                        activate_dialogue(event->heroine, 4, header_str);
                        break;

                    case CAFETERIA:
                        activate_dialogue(event->heroine, 5, header_str);
                        break;
                } 
                break;

			case 60:
                switch (event->place) {
                    case SCHOOL:
                        activate_dialogue(event->heroine, 6, header_str);
                        break;
                        
                    case CAFETERIA:
                        activate_dialogue(event->heroine, 7, header_str);
                        break;

                    case PARK:
                        activate_dialogue(event->heroine, 8, header_str);
                        break;
                }
				break;
			case 80:
                switch (event->place) {
                    case SCHOOL:
                        activate_dialogue(event->heroine, 9, header_str);
                        break;
                        
                    case CAFETERIA:
                        activate_dialogue(event->heroine, 10, header_str);
                        break;

                    case PARK:
                        activate_dialogue(event->heroine, 11, header_str);
                        break;
                }	
                break;
            case 100:
                switch (event->place) {
                    case SCHOOL:
                        activate_dialogue(event->heroine, 12, header_str);
                        break;
                        
                    case CAFETERIA:
                        activate_dialogue(event->heroine, 13, header_str);
                        break;

                    case PARK:
                        activate_dialogue(event->heroine, 14, header_str);
                        break;
                }	
                break;

        }
        

    }

    else if (strcmp(event->heroine->name, "Azure") == 0) {
        switch (event->heroine->intimacy){
            case 0:
                //ending dialogue
            case 20:
                activate_dialogue(event->heroine, 0, header_str);
                break;
            case 40:
                activate_dialogue(event->heroine, 1, header_str);
                break;
            case 60:
                activate_dialogue(event->heroine, 2, header_str);
                break;
            case 80:
                activate_dialogue(event->heroine, 3, header_str);
                break;
            case 100:
                activate_dialogue(event->heroine, 4, header_str);
                break;
            //case 60... and so on
        }
        
    }
    else if (strcmp(event->heroine->name, "Nadia") == 0) {
        switch (event->heroine->intimacy){
            case 0:
                activate_dialogue(event->heroine, 5, header_str);
                break;
            case 10:
                activate_dialogue(event->heroine, 6, header_str);
                break;
            case 20:
                activate_dialogue(event->heroine, 0, header_str);
                break;
            case 30:
                activate_dialogue(event->heroine, 7, header_str);
                break;
            case 40:
                activate_dialogue(event->heroine, 1, header_str);
                break;
            case 50:
                activate_dialogue(event->heroine, 8, header_str);
                break;
			case 60:
				activate_dialogue(event->heroine, 2, header_str);
				break;
            case 70:
                activate_dialogue(event->heroine, 9, header_str);
                break;
			case 80:
				activate_dialogue(event->heroine, 3, header_str);
                break;
            case 90:
                activate_dialogue(event->heroine, 10, header_str);
                break;
			case 100:
				activate_dialogue(event->heroine, 4, header_str);
                break;
            //case 60... and so on

        }


    }


}


void game() {

    int days; 

    days = 1;

    Event* event = initialize_events();
    Heroine* heroine_list = initialize_heroines();

    while (1==1) {

        if (event == NULL) {
            printf("<error>: events not connected\n");
            return;
        }

        //randomize both the place and the heroine
        event->place = random_up_to(PLACE_AMT);
        event->heroine = &heroine_list[random_up_to(HEROINE_AMT)];

        char place[MIN_STRLEN];

        char header_str[MAX_STRLEN];
        get_str_from_place(event->place, place);
        sprintf(header_str, "TIME: %s\nPLACE: %s\n", event->name, place);

        if (event->heroine->intimacy > 100) {
            char win_img[] = "                                      ████                 ███              ████                                 \n                                      ████          ████   ████   █████     █████                                \n                                     █████          ████   ████   ██████    █████                                \n                                     █████          ████   ████   ███████   █████                                \n                                     ████   ███    █████   ████   ████████   ████                                \n                                     ████  █████   █████   ████   ██████████ ████                                \n                                     ████ ██████  ██████   ████   ███████████████                                \n                                     ███████████ ███████   ████   ███████████████                                \n                                     ███████████████████   ████   ███████████████                                \n                                     ██████████████████    ████   █████ █████████                                \n                                     █████████████████     ████   █████  ████████                                \n                                     ███████ █████████     ████   █████    ██████                                \n                                     ██████   ███████      ████   █████      ████                                \n                                      ████     █████        ███     ███                                          \n                                                                                                                 \n";
            printf("\n\n\n\n\n");
            render_img(win_img, columns, 113);
            printf("\n\n");
            printf("congratulations, you have completed the game in %d day", days);

            if (days > 1) {
                printf("s.");
            }
            else {
                printf(".");
            }

            return;
        }

        if (event->heroine->intimacy < 0) {
            char lose_img[] = "                                                                                                                 \n                       ███                 ███████             ████████                                          \n                       █████             █████████████      █████████████   █████████████                        \n                       █████            ███████████████    ██████████████ ███████████████                        \n                       █████          █████████████████  █████████ ██████ ███████████████                        \n                       █████          ██████     ██████  ███████      ███ ████████                               \n                       █████          █████       █████  █████████          █████                                \n                       █████          █████       █████    ████████████     ████████████                         \n                       █████          █████       █████    ██████████████   ████████████                         \n                       █████          ██████     ██████        ███████████  ███████████                          \n                       █████          ████████████████             ███████  █████                                \n                       █████████████    ██████████████     ██████████████   ████████████                         \n                       ██████████████    ███████████       ██████████████   ████████████                         \n                       ██████████████      ███████         ███████████      ████████████                         \n                                                                                                                 \n";
            printf("\n\n\n\n\n");
            render_img(lose_img, columns, 113);
            printf("\n\n");
            printf("stupid loser! Better luck next time nyenye, you lost in %d day", days);

            if (days > 1) {
                printf("s.");
            }
            else {
                printf(".");
            }

            return;
        }

        event_handler(event, header_str);
        system("cls");
        event = event->next;
        if (strncmp(event->name, "MORNING", MIN_STRLEN) == 0) {
            days++;
            char next_day[] = "         ███                                                                        ████████    ██               \n ████    ████   ███████████   ████   █████   ███████████            █████████       ██████████  ████    █████    \n ███████ ████ █████████████   ████████████ ███████████              ████████████    ███    ███   ████████████    \n ████████████ ████████          ████████       ████                 ████    ████    ████   ███      ███████      \n ████████████  ██████████        ██████        ████                 ████   █████    ██████████      ████         \n ████ ███████    █████         █████████       ████                 ████████████    ███    ███     █████         \n ████    ████   ███████████   ████  ██████     ████                 █████████       ███    ███    ████           \n";
            printf("\n\n\n\n\n\n\n");
            printf("%.*s\n", columns, "======================================================================================================================================================================");
            printf("\n");

            render_img(next_day, columns, 113);
            printf("\n");
            printf("%.*s\n", columns, "======================================================================================================================================================================");
            printf("\n\n\n");
            printf("day %d completed", days);
            getch();
            system("cls");
        }
    }


}

int main(){
    setlocale(LC_ALL, "en_US.UTF-8");
    srand(time(NULL));

    game();

    getch();
    return 0;

}
