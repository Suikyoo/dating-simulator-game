
#ifndef ENUMS_H
#define ENUMS_H

enum PLACE;
enum STATUS;

typedef enum PLACE PLACE;
typedef enum STATUS STATUS;

enum PLACE {
    SCHOOL,
    CAFETERIA,
    PARK,
    PLACE_AMT

};

enum STATUS {
    STRANGER,
    ACQUAINTANCE

};


void get_str_from_place(int place, char* string);

#endif
