#include <string.h>
#include <stdlib.h>

#include "heroine.h"

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



