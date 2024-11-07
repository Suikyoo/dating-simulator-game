#include <stdio.h>
#include <time.h>
#include <stdlib.h>

enum PLACE;
enum STATUS;
struct Dialogue;
struct Heroine;
struct Event;

typedef enum PLACE PLACE;
typedef enum STATUS STATUS;
typedef struct Dialogue Dialogue;
typedef struct Heroine Heroine;
typedef struct Event Event;

//so yah, my guess was right, enums are basically like arrays
//an enum variable with the value of the first value declared in the enum would return an integer of 0 (first item). This is great since I can randomize the location
enum PLACE {
    CAFETERIA,
    PLAZA,
    HOUSE

};

enum STATUS {
    STRANGER,
    ACQUAINTANCE

};

struct Dialogue {
    char text[200];
    //there are three choices for the dialogue which points to other dialogues
    Dialogue* choices[3];

};

struct Heroine {
    Dialogue* dialogue;
    int love_meter = 0;
    STATUS status;

};

struct Event {
    PLACE place;
    Heroine* heroine;
    Event* next;
};

void connect_events(Event* before, Event* after) {
    Event* temp = before->next;
    before->next = after;
    after->next = temp;
}

Event* get_next_event(Event* event) {
    return event->next;
}


int main(){
    srand(time(NULL));

    return 0;

}
