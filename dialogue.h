#ifndef DIALOGUE_H

#define DIALOGUE_H


struct Dialogue;

typedef struct Dialogue Dialogue;

#include "conio.h"
#include "constants.h"
#include "heroine.h"

struct Dialogue {
    int intimacy_gain;

    char text[MAX_STRLEN];
    char choices[2][MAX_STRLEN];
    Dialogue* parent_dialogue;
    Dialogue* child_dialogues[2];



};

void clear();
void render_img(char* string, int win_width, int img_width);
char** initialize_images(char* heroine_name);

Dialogue* create_dialogue(char* text);

void append_dialogue(Dialogue* parent_dialogue, int i, char* text);
void next_dialogue(Dialogue** dialogue, int i);
void prev_dialogue(Dialogue** dialogue);

void create_choice(Dialogue* dialogue, int i, char* text);

Dialogue** initialize_dialogues(char* heroine_name);
int use_dialogue(Heroine* heroine, Dialogue* dialogue, char* header_str);

#endif


