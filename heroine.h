#ifndef HEROINE_H

#define HEROINE_H

struct Heroine;
typedef struct Heroine Heroine;

#include "dialogue.h"
#include "enums.h"
#include "constants.h"

struct Heroine {
    char name[MIN_STRLEN];
    int intimacy;

    Dialogue** dialogue_list;
    char** images;

    STATUS status;

};


void create_heroine(Heroine* heroine_list, int index, char* name);
void delete_heroines(Heroine* heroine_list);
Heroine* initialize_heroines();
char** initialize_images(char* heroine_name);

#endif
