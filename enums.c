
#include <string.h>

#include "enums.h"
#include "constants.h"


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
