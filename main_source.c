#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define CONSTANTS_H
#define HEROINE_AMT 1
#define MAX_STRLEN 200
#define MIN_STRLEN 30

enum PLACE;
enum STATUS;

struct Event;
struct Heroine;

struct Dialogue;

typedef struct Dialogue Dialogue;
typedef enum PLACE PLACE;
typedef enum STATUS STATUS;

typedef struct Event Event;
typedef struct Heroine Heroine;

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


void get_str_from_place(int place, char* string);


struct Dialogue {
    int intimacy_gain;

    char text[MAX_STRLEN];
    char choices[2][MAX_STRLEN];
    Dialogue* parent_dialogue;
    Dialogue* child_dialogues[2];



};

Dialogue* create_dialogue(char* text);

void append_dialogue(Dialogue* parent_dialogue, int i, char* text);
void next_dialogue(Dialogue** dialogue, int i);
void prev_dialogue(Dialogue** dialogue);

void create_choice(Dialogue* dialogue, int i, char* text);

Dialogue** initialize_dialogues(char* heroine_name);
int use_dialogue(Heroine* heroine, Dialogue* dialogue);


struct Heroine {
    char name[MIN_STRLEN];
    int intimacy;

    Dialogue** dialogue_list;
    STATUS status;

};


void create_heroine(Heroine* heroine_list, int index, char* name);
void delete_heroines(Heroine* heroine_list);
Heroine* initialize_heroines();



struct Event {
    char name[MIN_STRLEN];
    PLACE place;
    Heroine* heroine;
    Event* next;
};

Event* create_event(char* name);
void connect_events(Event* before, Event* after);
void delete_events(Event* event);
Event* initialize_events();

void event_handler(Event* event);

//so yah, my guess was right, enums are basically like arrays
//an enum variable with the value of the first value declared in the enum would return an integer of 0 (first item). This is great since I can randomize the location
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

Heroine* initialize_heroines() {
    Heroine* heroine_list = (Heroine*) malloc(sizeof(Heroine) * HEROINE_AMT);

    create_heroine(heroine_list, 0, "Andre");

    return heroine_list;

}



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


void activate_dialogue(Heroine* heroine, int dialogue_index) {
    printf("%d", heroine->intimacy);
    heroine->intimacy = heroine->intimacy + use_dialogue(heroine, heroine->dialogue_list[dialogue_index]);
    printf("(press any character to continue)");
    getch();
    clear();
}

Event* create_event(char* name) {
    Event* ptr = (Event*) malloc(sizeof(Event));
    ptr->heroine = NULL;
    ptr->next = NULL;
    strncpy(ptr->name, name, MIN_STRLEN);

    return ptr;
}

void connect_events(Event* before, Event* after) {
    Event* temp = before->next;
    before->next = after;
    after->next = temp;
}

void delete_events(Event* event) {
    Event* ptr = event;
    while (ptr != NULL) {
        Event* temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
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

Dialogue** initialize_dialogues(char* heroine_name) {
    //initialize a dialogue list of size 50 through malloc()

    Dialogue** dialogue_list = (Dialogue**) malloc(sizeof(Dialogue*) * 50);

    Dialogue* head;

    //these dialogues are actually owned by the heroine. Only the choices are from the users.
    //create these dialogues from the perspective of the heroine.
    if (strcmp(heroine_name, "Andre") == 0) {

        //dialogue[0]
        //the head variable is the current dialogue node we're in. 
        //Just like in a file system, this is our current directory.

        //a dialogue is composed of a text, and an intimacy_gain integer(only set at the end of a conversation)
        //it also may contain a left and right side

        //conversation - 1
        //---------------first ever dialogue-----------------
        head = create_dialogue("Good morning");
        dialogue_list[0] = head;


        //in this dialogue, we call the left side as 0 and 1 for the right
        create_choice(head, 0, "Good morning too");
        create_choice(head, 1, "What's good abt the morning");

        append_dialogue(head, 0, "Hey wanna grab some coffee?");
        append_dialogue(head, 1, "Oh! S-sorry. :<");

        //the choice "good morning too" (situated on the left) leads to a child dialogue of "Hey wanna grab some coffee?"

        //---------------first ever dialogue-----------------


        //append_dialogue() creates a child dialogue at eiher the left or right side
        //but it doesn't where our current node `head` is located
        //to do that, we must use next_dialogue(&head, 0 or 1 [left or right]) 
        //to indicate that we want to change our current node to that of either its left or right child node
        //to access the right child node "Oh! S-sorry. :<"  of the current head "Good morning", use next_dialogue(&head, 
        next_dialogue(&head, 1);
        //give that dialogue some points
        head->intimacy_gain = 20;
        //and then go back to the previous node
        prev_dialogue(&head);

        //now we're back at the head node "Good morning" 
        //and we now wanna access its left child "Hey wanna grab some coffee?"
        next_dialogue(&head, 0);

        //--------another dialogue development------------------

        //we create both the choices and their resulting dialogues for both the right and left sides
        create_choice(head, 0, "Um, I'm actually quite busy right now");
        create_choice(head, 1, "Yeah sure!");

        append_dialogue(head, 0, "Ok! Maybe next time then ^-^");
        append_dialogue(head, 1, "Really?!? W-where should we go then?");

        //--------another dialogue development------------------

        next_dialogue(&head, 0);
        head->intimacy_gain = 0;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = 20;

        //end of conversation - 1
        //----------------------------------------------------------------
        //conversation - 2
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
        //end of conversation 2
    }


    return dialogue_list;
}

void event_handler(Event* event) {
    if (strcmp(event->heroine->name, "Andre") == 0) {
        switch (event->heroine->intimacy){
            case 0:
                //ending dialogue
            case 20:
                activate_dialogue(event->heroine, 0);
                break;
            case 40:
                activate_dialogue(event->heroine, 1);
                break;
            //case 60... and so on

        }
        

    }

}


