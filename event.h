#ifndef EVENT_H
#define EVENT_H

struct Event;
typedef struct Event Event;


#include "constants.h"
#include "enums.h"
#include "heroine.h"

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



#endif
