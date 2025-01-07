
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "event.h"

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


    return morning;

}


