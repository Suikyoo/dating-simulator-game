#ifndef DIALOGUE_H

#define DIALOGUE_H


struct Dialogue;
struct Choice;

typedef struct Dialogue Dialogue;
typedef struct Choice Choice;

#include "constants.h"
#include "heroine.h"

struct Dialogue {
    char text[MAX_STRLEN];
    Choice* choices[2];


};

struct Choice {
    char text[MAX_STRLEN];
    int intimacy_gain;
    Dialogue* next;
};


Choice* create_choice(char* text, int intimacy_gain);
Dialogue* create_dialogue(char* text);
Dialogue** initialize_dialogues(char* heroine_name);
int use_dialogue(Heroine* heroine, Dialogue* dialogue);

#endif


