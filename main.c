#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//so yah, my guess was right, enums are basically like arrays
//an enum variable with the value of the first value declared in the enum would return an integer of 0 (first item). This is great since I can randomize the location
enum location {
    CAFETERIA,
    PLAZA,
    HOUSE
};

enum heroine_status {


};

struct Dialogue {
    char text[200];
    //there are three choices for the dialogue which points to other dialogues
    struct Dialogue choices[3];

};

struct Heroine {
    struct Dialogue dialogue;
    int love_meter;
    enum heroine_status;

};

int main(){
    srand(time(NULL));
    enum location place;
    place = Cafeteria;
    printf("%d", place);


    return 0;

}
