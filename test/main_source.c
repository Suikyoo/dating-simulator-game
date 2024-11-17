#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define HEROINE_AMT 1
#define MAX_STRLEN 200
#define MIN_STRLEN 30

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

//misc functions
void clear();
int random_up_to(int value);

//enum functions
void get_str_from_place(int place, char* string);

//event functions
void connect_events(Event* before, Event* after);
Event* create_event(char* name);
Event* initialize_events();
void delete_events(Event* event);

//dialogue functions
Choice* create_choice(char* text, int intimacy_gain);
Dialogue* create_dialogue(char* text);
Dialogue** initialize_dialogues(char* heroine_name);
int use_dialogue(Heroine* heroine, Dialogue* dialogue);

//heroine functions
void create_heroine(Heroine* heroine_list, int index, char* name);
void delete_heroines(Heroine* heroine_list);
void converse(Heroine* heroine, int dialogue_index);
Heroine* initialize_heroines();

//collab functions
void event_handler(Event* event);
int game();
int main();



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
    Dialogue* next;
};

struct Heroine {
    char name[MIN_STRLEN];
    int intimacy;

    Dialogue** dialogue_list;
    STATUS status;

};

struct Event {
    char name[MIN_STRLEN];
    PLACE place;
    Heroine* heroine;
    Event* next;
};

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

void get_str_from_place(int place, char* string) {
    switch (place) {
        case CAFETERIA:
            strncpy(string, "CAFETERIA", MIN_STRLEN);
            break;

        case PLAZA:
            strncpy(string, "PLAZA", MIN_STRLEN);
            break;

        case HOUSE:
            strncpy(string, "HOUSE", MIN_STRLEN);
            break;

        default:
            strncpy(string, "NONE", MIN_STRLEN);
    }
}

//event functions
void connect_events(Event* before, Event* after) {
    Event* temp = before->next;
    before->next = after;
    after->next = temp;
}

Event* create_event(char* name) {
    Event* ptr = (Event*) malloc(sizeof(Event));
    ptr->heroine = NULL;
    ptr->next = NULL;
    strncpy(ptr->name, name, MIN_STRLEN);

    return ptr;
}

Event* initialize_events() {
    Event* morning = create_event("MORNING");
    Event* noon = create_event("NOON");
    Event* afternoon = create_event("AFTERNOON");
    Event* evening = create_event("EVENING");

    morning->next = noon;
    noon->next = afternoon;
    afternoon->next = evening;
    evening->next = morning;

    //chain it

    return morning;

}

void delete_events(Event* event) {
    Event* ptr = event;
    while (ptr != NULL) {
        Event* temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}

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

//heroine functions

void create_heroine(Heroine* heroine_list, int index, char* name) {
    Heroine heroine;
    strncpy(heroine_list[index].name, name, MIN_STRLEN);
    heroine_list[index].intimacy = 20;
    heroine_list[index].dialogue_list = initialize_dialogues(name);
}

void delete_heroines(Heroine* heroine_list) {
    for (int i=0; i<HEROINE_AMT; i++) {
        free(heroine_list[i].dialogue_list);
    }

    free(heroine_list);

}

void converse(Heroine* heroine, int dialogue_index) {
    heroine->intimacy = heroine->intimacy + use_dialogue(heroine, heroine->dialogue_list[dialogue_index]);
    printf("(press any character to continue)");
    getch();
    clear();
}

Heroine* initialize_heroines() {
    Heroine* heroine_list = (Heroine*) malloc(sizeof(Heroine) * HEROINE_AMT);

    create_heroine(heroine_list, 0, "Andre");

    return heroine_list;

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

void event_handler(Event* event) {
    if (strcmp(event->heroine->name, "Andre") == 0) {
        converse(event->heroine, 0);
        //collab

    }

}



Dialogue** initialize_dialogues(char* heroine_name) {
    //initialize a dialogue list of size 50 through malloc()

    Dialogue** dialogue_list = (Dialogue**) malloc(sizeof(Dialogue*) * 50);

    Dialogue* dialogue;
    Choice* choices[2];

    if (strcmp(heroine_name, "Andre") == 0) {

        //sample:

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


