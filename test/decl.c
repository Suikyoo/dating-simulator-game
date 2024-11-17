
//misc functions
void clear();
int random_up_to(int value);

//enum functions
void get_str_from_place(int place, char* string);

//event functions
void connect_events(Event* before, Event* after);
Event* create_event(char* name);
Event* initialize_events();
void delete_events(Event* event);

//dialogue functions
Choice* create_choice(char* text, int intimacy_gain);
Dialogue* create_dialogue(char* text);
Dialogue** initialize_dialogues(char* heroine_name);
int use_dialogue(Heroine* heroine, Dialogue* dialogue);

//heroine functions
void create_heroine(Heroine* heroine_list, int index, char* name);
void delete_heroines(Heroine* heroine_list);
void converse(Heroine* heroine, int dialogue_index);
Heroine* initialize_heroines();

//collab functions
void event_handler(Event* event);
int game();
int main();
