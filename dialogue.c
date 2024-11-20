#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "constants.h"
#include "heroine.h"

#include "dialogue.h"




//dialogue functions
Dialogue* create_dialogue(char* text) {
    Dialogue* dialogue = (Dialogue*) malloc(sizeof(Dialogue));
    strncpy(dialogue->text, text, MAX_STRLEN);

    dialogue->intimacy_gain = 0;

    dialogue->child_dialogues[0] = NULL;
    dialogue->child_dialogues[1] = NULL;

    dialogue->parent_dialogue = NULL;

    return dialogue;
}

void create_choice(Dialogue* dialogue, int i, char* text) {
    strncpy(dialogue->choices[i], text, MAX_STRLEN);


}
void append_dialogue(Dialogue* parent, int i, char* text) {
    Dialogue* dialogue = create_dialogue(text);

    parent->child_dialogues[i] = dialogue;
    parent->child_dialogues[i]->parent_dialogue = parent;

}

void next_dialogue(Dialogue** dialogue, int i){
    *dialogue = (*dialogue)->child_dialogues[i];

}

void prev_dialogue(Dialogue** dialogue){
    *dialogue = (*dialogue)->parent_dialogue;
    
}

Dialogue** initialize_dialogues(char* heroine_name) {
    //initialize a dialogue list of size 50 through malloc()

    Dialogue** dialogue_list = (Dialogue**) malloc(sizeof(Dialogue*) * 50);

    Dialogue* head;

    //these dialogues are actually owned by the heroine. Only the choices are from the users.
    //create these dialogues from the perspective of the heroine.
    if (strcmp(heroine_name, "Andre") == 0) {

        //dialogue[0]
        head = create_dialogue("Good morning");
        dialogue_list[0] = head;

        create_choice(head, 0, "Good morning too");
        create_choice(head, 1, "What's good abt the morning");

        append_dialogue(head, 0, "Hey wanna grab some coffee?");
        append_dialogue(head, 1, "Oh! S-sorry. :<");

        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 0);

        create_choice(head, 0, "Um, I'm actually quite busy right now");
        create_choice(head, 1, "Yeah sure!");

        append_dialogue(head, 0, "Ok! Maybe next time then ^-^");
        append_dialogue(head, 1, "Really?!? W-where should we go then?");

        next_dialogue(&head, 0);
        head->intimacy_gain = 0;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        //----------------------------------------------------------------
        //
        head = create_dialogue("Oh nice to see you again");
        dialogue_list[1] = head;
        create_choice(head, 0, "Wow I didn't expect to see you again so soon");
        create_choice(head, 1, "You look gorgeous today");

        append_dialogue(head, 0, "You must not want to see me then huh? o_o");
        append_dialogue(head, 1, "Really? You're just teasing me -_-");

        next_dialogue(&head, 0);

        create_choice(head, 0, "T-that's not what I meant! I was just surprised to see you...");
        create_choice(head, 1, "N-no that's not it at all. Of course I wanna see you");

        append_dialogue(head, 0, "Ahahahahah you're quite the shy one aren't you?");
        append_dialogue(head, 1, "0-0. Ah I g-gotta hurry. I think I'm gonna be late for classes");
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        prev_dialogue(&head);

        next_dialogue(&head, 1);

        create_choice(head, 0, "Of course not. You're beautiful");
        create_choice(head, 1, "Of course I am");

        append_dialogue(head, 0, ":> Well my friends are calling me now. I hope to see you next time!");
        append_dialogue(head, 1, "-_- you bastard");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
    }


    return dialogue_list;
}

//recursive iteration
int use_dialogue(Heroine* heroine, Dialogue* dialogue) {
    char input;
    int gain;

    gain = dialogue->intimacy_gain;

    printf("\n");
    printf("=============================\n");
    printf("%s: %s\n", heroine->name, dialogue->text);
    printf("=============================\n");

    if (dialogue->child_dialogues[0] != NULL && dialogue->child_dialogues[1]  != NULL) {


        printf("X: %s\n", dialogue->choices[0]);
        printf("Y: %s\n\n", dialogue->choices[1]);
        printf("choice: ");
        scanf(" %c", &input);

        switch (tolower(input)) {
            case 'x':
                dialogue = dialogue->child_dialogues[0];
                break;

            case 'y':
                dialogue = dialogue->child_dialogues[1];
                break;

            default:
                printf("input does not match any of the choices. Please try again.");
                getch();

                
        }

        gain = gain + use_dialogue(heroine, dialogue);
    }

    return gain;
}


