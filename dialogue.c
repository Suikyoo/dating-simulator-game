#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "constants.h"
#include "heroine.h"

#include "dialogue.h"


//choice functions
Choice* create_choice(char* text, int intimacy_gain) {
    Choice* choice = (Choice*) malloc(sizeof(Choice));
    strncpy(choice->text, text, MAX_STRLEN);
    choice->intimacy_gain = intimacy_gain;

    return choice;
}

//dialogue functions
//
Dialogue* create_dialogue(char* text) {
    Dialogue* dialogue = (Dialogue*) malloc(sizeof(Dialogue));
    strncpy(dialogue->text, text, MAX_STRLEN);
    dialogue->choices[0] = NULL;
    dialogue->choices[1] = NULL;
    return dialogue;
}

Dialogue** initialize_dialogues(char* heroine_name) {
    //initialize a dialogue list of size 50 through malloc()

    Dialogue** dialogue_list = (Dialogue**) malloc(sizeof(Dialogue*) * 50);

    if (strcmp(heroine_name, "Andre") == 0) {

        //sample:
        Dialogue* dialogue;
        Choice* choices[2];

        dialogue = create_dialogue("hallo senpai, uwwwuwuwuwuw");
        dialogue->choices[0] = create_choice("sup homie", 20);
        dialogue->choices[1] = create_choice("nah idk you", -20);


        //link these dialogues to the choices
        dialogue->choices[0]->next = create_dialogue("eyoo sup bows");
        dialogue->choices[1]->next = create_dialogue("ka oa ba nimo");
        
        dialogue_list[0] = dialogue;

    }

    return dialogue_list;
}

//recursive iteration
int use_dialogue(Heroine* heroine, Dialogue* dialogue) {
    char input;
    int gain;
    Choice* choice;

    gain = 0;

    printf("\n");
    printf("=============================\n");

    printf("%s: %s\n", heroine->name, dialogue->text);
    printf("=============================\n");

    if (dialogue->choices[0] != NULL && dialogue->choices[1]  != NULL) {

        printf("X: %s\n", dialogue->choices[0]->text);
        printf("Y: %s\n\n", dialogue->choices[1]->text);
        printf("choice: ");
        scanf(" %c", &input);

        switch (tolower(input)) {
            case 'x':
                choice = dialogue->choices[0];
                break;

            case 'y':
                choice = dialogue->choices[1];
                //use_dialogue(heroine, dialogue->choice[1]->dialogue);
                break;

            default:
                choice == NULL;
                
        }

        if (choice != NULL) {
            gain = gain + use_dialogue(heroine, choice->next);

        }
        else {
            printf("input does not match any of the choices.");
            gain = gain + use_dialogue(heroine, dialogue);
        }
    }

    return gain;
}


