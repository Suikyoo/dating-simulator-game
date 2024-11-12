#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HEROINE_AMT 1
#define MAX_STRLEN 200

enum PLACE;
enum STATUS;
struct Dialogue;
struct Choice;
struct Heroine;
struct Event;

typedef enum PLACE PLACE;
typedef enum STATUS STATUS;
typedef struct Dialogue Dialogue;
typedef struct Choice Choice;
typedef struct Heroine Heroine;
typedef struct Event Event;

//so yah, my guess was right, enums are basically like arrays
//an enum variable with the value of the first value declared in the enum would return an integer of 0 (first item). This is great since I can randomize the location
enum PLACE {
    CAFETERIA,
    PLAZA,
    HOUSE,
    PLACE_AMT

};

enum STATUS {
    STRANGER,
    ACQUAINTANCE

};

struct Dialogue {
    char text[MAX_STRLEN];
    //there are 2 ptrs pointing at a choice struct with the choice-text and its corresponding dialogue
    Choice* choices[2];


};

struct Choice {
    char text[MAX_STRLEN];
    int intimacy_gain;
    Dialogue* dialogue;
};

struct Heroine {
    Dialogue* dialogue;
    int love_meter;
    STATUS status;

};

struct Event {
    PLACE place;
    Heroine* heroine;
    Event* next;
};

//randomizer functions

//randomizes up to an excluded number
int random_up_to(int value) {
    return rand() % value;

}

//event functions
void connect_events(Event* before, Event* after) {
    Event* temp = before->next;
    before->next = after;
    after->next = temp;
}

Event* create_event() {
    Event* ptr = (Event*) malloc(sizeof(Event));
    ptr->heroine = NULL;
    ptr->next = NULL;

    return ptr;
}

Event* initialize_events() {
    Event* event = create_event();
    //chain it

    return event;

}

void delete_events(Event* event) {
    Event* ptr = event;
    while (ptr != NULL) {
        Event* temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}

//heroine functions
Heroine* initialize_heroines() {
    Heroine* heroine_list = (Heroine*) malloc(sizeof(Heroine) * HEROINE_AMT);
    //create the heroines here

    return heroine_list;

}

void delete_heroines(Heroine* heroine_list) {
    free(heroine_list);
}

//dialogue functions

Dialogue* create_dialogue() {
    Dialogue* dialogue = (Dialogue*) malloc(sizeof(Dialogue));
    dialogue->choices[0] = NULL;
    dialogue->choices[1] = NULL;
    return dialogue
}

//should probably put this on a separate function group
Choice* create_choice() {
    Choice* choice = (Choice*) malloc(sizeof(Choice));
    choice
    return choice;
}

Dialogue** initialize_dialogues() {
    //initialize a dialogue list of size 50 through malloc()
    Dialogue** dialogue_list = (Dialogue**) malloc(sizeof(Dialogue*) * 50);

    //sample:
    Dialogue* dialogue;
    Choice* choices[2];

    dialogue = create_dialogue();
    dialogue->choices[0] = create_choice();
    dialogue->choices[1] = create_choice();
    //instead of dialogue->text = "hallo senpai, uwuwuwuwu";
    //do:
    
    //set dialogue text
    strncpy(dialogue->text, "hallo senpai, uwuwuwuwu", MAX_STRLEN);

    //set choices text
    strncpy(dialogue->choices[0]->text, "sup homie", MAX_STRLEN);
    strncpy(dialogue->choices[1]->text, "nah idk you", MAX_STRLEN);

    //set choice gains 
    dialogue->choices[0]->intimacy_gain = 20
    dialogue->choices[1]->intimacy_gain = -20

    //set to dialogue list
    dialogue_list[0] = dialogue;

    dialogue = create_dialogue();

    strncpy(dialogue->text, "eyoo sup homie", MAX_STRLEN);
    dialoguelist[0]->choices[0]->dialogue = dialogue
    
    dialogue = create_dialogue();

    strncpy(dialogue->text, "oa", MAX_STRLEN);
    dialoguelist[0]->choices[1]->dialogue = dialogue

    return dialogue_list;
}

//recursive iteration
int use_dialogue(Heroine* heroine, Dialogue* dialogue) {
    char input;
    int gain;
    Choice* choice;

    gain = 0;

    if (dialogue->choice[0] != NULL && dialogue->choice[1]  != NULL) {

        printf("%s: %s\n", heroine->name, dialogue->text);
        printf("X: %s\n", dialogue->choice[0]->text);
        printf("Y: %s\n", dialogue->choice[1]->text);
        scanf("%c", &input);

        switch (tolower(input)) {
            case 'x':
                choice = dialogue->choice[0];
                break;

            case 'y':
                choice = dialogue->choice[1];
                //use_dialogue(heroine, dialogue->choice[1]->dialogue);
                break;

            default:
                choice == NULL;
                
        }

        if (choice != NULL) {
            gain = gain + useDialogue(heroine, choice->dialogue);
        }
        else {
            printf("input does not match any of the choices.");
            gain = gain + useDialogue(heroine, dialogue);
        }
    }

    return gain;
}

void condition_handler(Event* event) {
    if (strcmp(event->heroine->name, "Andre") == 0) {
        //collab



    }

}

int game() {

    Event* event = initialize_events();
    heroine_list = initialize_heroines();

    while (1==1) {

        if (event == NULL) {
            printf("<error>: events not connected\n");
            return days
        }
        else {
            //randomize both the place and the heroine
            event->place = random_up_to(PLACE_AMT);
            event->heroine = &heroine_list[random];
        }


        condition_handler();

        event = event->next;
    }


}

int main(){

    srand(time(NULL));

    int days;

    days = game();

    printf("congratulations, you have completed the game in %d days.", days);

    return 0;

}
