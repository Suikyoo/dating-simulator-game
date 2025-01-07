#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

#include "constants.h"
#include "heroine.h"

#include "dialogue.h"

//image functions

int columns;
void render_img(char* string, int win_width, int img_width) {
    //just needed a number to set as max column
    char string_render[MAX_IMGLEN];
    strncpy(string_render, string, MAX_IMGLEN);
    
    char* token = strtok(string_render, "\n");


    while (token != NULL) {
        int offset = (win_width/2) - img_width/2;
        for (int i=0; i<offset; i++){
            printf(" ");
        }
        printf("%s", token);
        printf("\n");

        token = strtok(NULL, "\n");
    }

}

char** initialize_images(char* heroine_name) {
    char** images = (char**) malloc(sizeof(char*) * 3);

    //ayw nlg pangutana, basta MAX_IMGLEN na
    if (strncmp(heroine_name, "Mio", MIN_STRLEN) == 0) {
        images[0] = (char*) malloc(sizeof(char) * MAX_IMGLEN);
        strncpy(images[0], "                                               █████████████████░░▓▓█████ ███                   ▒▒▒▒▒            \n                                             ███████████████████░░░▓▓████████                 ▒▒▒▒▒▒▒▒▒  ▒▒▒▒    \n                                            ████████████████████░░░░▓▓▓▓▓▓█████              ▒   ▒▒▒▒▒  ▒▒▒▒▒▒▒  \n                   ▒▒▒▒░░                  █████████████████████░░░░░▓▓▓▓▓█ ████                       ▒▒▒▒▒▒▒▒▒ \n                  ▒▒▒▒▒▒░░░                ██▓█████████████░████░░░░░░▓▓▓▓█    ██                   ▒  ▒▒▒▒▒▒▒▒▒ \n                 ▒▒▒▒▓▓▓▓░░░░              ▓▓▓█████▓▓██████░█████░░░░░▓▓▓▓▓    ██                ▒▒▒▒▒ ▒▒▒▒▒▒▒▒▒ \n          ▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓░░░░             ▓▓▓███▓▓▓▓████░░░░░███░▒░░░▓▓▓▓▓▓   ██              ▒▒▒▒▒▒   ▒▒▒▒▒▒▒  \n         ▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓░░░░░░░░         ▓▓▓▓██▓▓▓▓████░░░░░░░░░▒▒░░░▓▓▓▓▓                  ▒▒▒▒       ▒▒▒▒▒▒  \n        ▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓░░░░░░░░░       ▓▓▓▓▓▓▓▓▓████░░░░░░░░░░▒▒▒░░▓▓▓                    ▒▒                 \n        ▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓░░▒▓▒▒▒░░░        ▓▓▓▓▓▓████░░░░░░░░░░░░▒▒░░▓▓        ▒             ▒      ▒▒         \n        ▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓░▒▓▓▓▓▓▒░░░        ▓▓▓▓▓████░░░░░░░░░░░░░░░░▓▓   ▒▒▒▒▒▒▒             ▒    ▒▒▒▒▒    ▒  \n        ▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▒▒░░         ▓▓▓▓▓█▓▓▓░░░░░░░░░░░░▒░░  ▒▒▒▒▒▒▒▒▒▒                 ▒▒▒▒▒▒    ▒▒ \n        ▒▒▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▓▓▓▓▓▓▒░░            ▓▓▓▓▓▓▓░░▒▒▒▒▒▒▒░▒░░░▒▒▒▒▒▒▒▒▒▒▒▒▒                ▒▒▒▒▒     ▒▒ \n       ▒▒▒▒▒▓▓▓▓▓▓▓▒▒▓▓▓▓▒░▒▒▒▓▓▓▓▓▒░░              ▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░░░░▒▒▒▒▒▒▒▒▒▒▒                 ▒▒▒▒▒     ▒▒▒ \n       ▒▒▒▒▒▓▓▓▓▓▓▓▒▒▒▒▒▒░░▒▒▒▒▓▓▓▒░░              ▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░▒▒▒▒▒▒▒▒▒▒▒                 ▒▒▒▒▒    ▒▒▒▒  \n", MAX_IMGLEN);
    }

    else if (strncmp(heroine_name, "Azure", MIN_STRLEN) == 0) {
        images[0] = (char*) malloc(sizeof(char) * MAX_IMGLEN);
        strncpy(images[0], "                                        ███▒▒▒▒████████░░░░░█████                      ▓▓▓▓▓▓       \n                    ░                  ▒██▒▒▒███████░░░███░░██████            ▓       ▓▓▓▓▓▒▒▓      \n    ▓▓              ░░                 ▒▒▒█████░░░░░░░▒▒▒░█░░░████             ▓     ▓▓▓▓▒▒▒▒▒▒     \n    ▓▓              ░░░                ▒██████░░░░░░░░▒▒▒▒▒▒░░░░███            ▓▓    ▓▓▓▒▒   ▒▒     \n    ▓▓▒              ░░░               ████░░░░░░░▒▒▒▒▒▒▒█▒▒▒▒░░▒██    ▓       ▓▓    ▓▓▒▒     ▒ ▒▒  \n     ▓▒      ▓        ░░▒▒▓▓           ░░░░░░███░░░░▒▒▒▒▒▒████▒▒▒▒      ▓      ▓▓▓   ▓▒▒▒     ▒ ▒▒▒ \n     ▒▒       ▓▓    ░░▓▓░░▒▒▒           ░░░██░░░░░░░░░░░▒▒▒█████▒░      ▓▓    ▒▒▓▓   ▓▒▒▒     ▒  ▒▒ \n       ▒      ▒▓▓     ▒▒▓░▒▒▒           ░██░░░░░░▒░░░░░░░░▒▒▒████░       ▓▓   ▒▒▒▓    ▓▒      ▒     \n               ▒▒   ░░░▒▒▒▒▒▒           ▒██░░░░░░▒▒░░░░░░░░▒▒▒▒▒░        ▒▓▓  ▓▒▒▒    ▓▒▒▒   ▒▒ ▒   \n        ▓▓ ▓▓        ░░▒▒▒▒▒▒░          █▒▒░░░░░▒▒▒░░░░░░░░▒▓▓▒▒   ▓▓▓    ▒▒▓▓▓▒▒▒     ▒▒▒▒▒▓▒      \n        ▓▓▓▒▒▒        ▓▓▓▓▓▓▒░░         ▒░░░░░░░░░▒░░░░░░░▓▓▒▒    ▓▓▓▒▒    ▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒       \n         ▓▓▒▒▒        ▒▓▓▓▓▓▓░░░         ▒░░░░░░░░░░░░░░░░▓▒▒▒    ▓▒▒▒▒     ▒▒▓▓▒▒▒▒▒▒▒▒▓▒▒▒        \n           ▒▒        ▓▓▒▒▒▒▓▓▓░░        ▓▒░░░░░░░░░░░░░░░░▒▒▓▓▓   ▒▒▒▒       ▒▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒       \n                     ▓▓▓▒▒▒▓▓▓         ▓▓▓▒░░░░░▒▒▒░▒░░░░▓▓▓▓▓▒▒   ▒▒        ▒▓▒▒▒▒▒▒▒▒▒  ▒▒▒▒      \n                     ▒▒▒▓▓▓▒▓▓      ▒▓▓▒▒▒▓░░░░▒░░░░░░░░░▓▓▓▒▒▒▒▒▒          ▒▒▒▒▒           ▒▒      \n", MAX_IMGLEN);
    }
    
    else {
        images[0] = (char*) malloc(sizeof(char) * MAX_IMGLEN);
        strncpy(images[0], "              ▓▓▓                ░     ██▓███▓▓▓░░░░░░█▓███████▓        ▓▓▓▓             ▓▓▓▓▓▓▓▓▓  \n             ▓▓▓▓        ▓            ██▓▓██▓▓▓░░░░░░░▓▓▓██▓███▓        ▓▓▓▓  ▓▒        ▓▓▓▓▓▓▓     \n             ▓▓▓▓        ▒▓           ██▓██▓▓░░░░░░░░░░█▓▓██▓▓██       ▓▓▓▓   ▓▒        ▓▓▓▓        \n             ▓▓▓▓        ▒▓           █▓███▓░░░░░░░░░░░█░▓▓█▓▓ █▓     ▓▓▓▓   ▓▒        ▓▓▓▓      ▓▓▓\n            ▓▓▓▓▓         ▒▓          █▓███▓░░░░░░░░░░░█░░▓▓█▓ ██▓          ▓▒▒        ▓▓▓      ▓▓▓▓\n            ▓▓▓▓          ▒▒▓         ███▓▓▓░░░░░░░░░░░█▓░░▓▓█  █▓         ▓▒▒     ▓▒  ▓▓▓      ▓▓▓▓\n   ▓       ▓▓▓▓▓           ▒▒▒        ███▓█▓░░░░░░░░░░░█▓░░░▓▓▓ █▓          ▒▒    ▓▒▒  ▓▓▓      ▓▓▓▓\n    ▓     ▓▓▓▓▓      ▓ ▓    ▒▒         █▓▓█▓░░░░░░░░▒░░█▓░░░▓▓▓▓▓▓        ▒ ▒   ▓▓▒▒    ▓▓      ▓▓▓▓\n    ▓     ▓▓▓▓      ▒ ▒▓▓▓     ▓▓      ▓▓▓█▓░░░░░░░░▒░░█▓▓░░░▓▓▓▓        ▓▓▒  ▓▓▒▒▒     ▓▓       ▓▓▓\n   ▓     ▓▓▓▓      ▒▒ ▒▒▓▓▓   ▒▓▓▓     ▓▓██▓░░░░░░░░▒▒░░█▓▓░░▓▓▓▓      ▒▓▓▓▒ ▒▒▒▒▒       ▓▓       ▓▓\n ▓▓▓    ▓▓▓▓      ▒    ▒▒▒  ▒▒▒▒▓▓▓    ▓▓▓░░░░░░░░░░▒▒░░░▓▓▓▓▓▓ █    ▒▒▓▓▓▒▒▒ ▒          ▓▓▓▓       \n▓▓▓    ▓▓▓▓                ▒▒▓▓▓▓▓▓▓   ▓▓ ░░░░░░░░░░▒░░░░░░░▓▓  █   ▒▒▓▓▓▓▓▓▒▒            ▓▓▓▓▓▓▓   \n▓▓    ▓▓                   ▒▒▒▓▓▓▓▓▓▓     ░░░░░░░░░░░░░░░░░░ █  █  ▒▒▓▓▓▒▒▒▒▒▒ ▓▓▓          ▓▓▓▓    \n     ▓▓                ▓▓  ▒▒▒▒▒▓▓▓▒▒▓    ░░░░░░░░░░░░░░░░░░ ▓  ▓ ▒▒▓▓▒▒▒▒▓▒▒  ▒▒▒▒                 \n   ▓▓                 ▒▒▒  ▒▓▓▓▒▒▓▓▓▒▒▒    ░░░░░░░░░░░░░░░░   ▓▓ ▒▒▓▒▒▒▓▓▓▒▒▒▒   ▒▒▒▒               \n", MAX_IMGLEN);
    }

    return images;

}

//dialogue functions
Dialogue* create_dialogue(char* text) {
    Dialogue* dialogue = (Dialogue*) malloc(sizeof(Dialogue));
    strncpy(dialogue->text, text, MAX_STRLEN);

    dialogue->intimacy_gain = 0;

    dialogue->child_dialogues[0] = NULL;
    dialogue->child_dialogues[1] = NULL;

    dialogue->parent_dialogue = NULL;

    return dialogue;
}

void create_choice(Dialogue* dialogue, int i, char* text) {
    strncpy(dialogue->choices[i], text, MAX_STRLEN);


}
void append_dialogue(Dialogue* parent, int i, char* text) {
    Dialogue* dialogue = create_dialogue(text);

    parent->child_dialogues[i] = dialogue;
    parent->child_dialogues[i]->parent_dialogue = parent;

}

void next_dialogue(Dialogue** dialogue, int i){
    *dialogue = (*dialogue)->child_dialogues[i];

}

void prev_dialogue(Dialogue** dialogue){
    *dialogue = (*dialogue)->parent_dialogue;
    
}

Dialogue** initialize_dialogues(char* heroine_name) {
    //initialize a dialogue list of size 50 through malloc()

    Dialogue** dialogue_list = (Dialogue**) malloc(sizeof(Dialogue*) * 50);

    Dialogue* head;

    //these dialogues are actually owned by the heroine. Only the choices are from the users.
    //create these dialogues from the perspective of the heroine.
    if (strcmp(heroine_name, "Mio") == 0) {
        // Schoool
        head = create_dialogue("H-hey, loser! I saw your terrible test scores. Do you even study? N-not that I care, but you need to do better!");
        dialogue_list[0] = head;
        create_choice(head, 0, "Thanks for worrying about me. I'll study harder next time!");
        create_choice(head, 1, "Why are you even looking at my scores?");
        append_dialogue(head, 0, "W-what?! I’m not worried! J-just don’t embarrass yourself, okay?");
        append_dialogue(head, 1, "Tch! I wasn’t looking! I just...happened to see them!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20; 
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20; 
        prev_dialogue(&head);

        // Cafeteria 
        head = create_dialogue("Ugh, why are you sitting here? It’s not like I wanted to share my lunch or anything, but here! I made extra, okay?");
        dialogue_list[1] = head;
        create_choice(head, 0, "Wow, you made this? Thanks, it looks delicious!");
        create_choice(head, 1, "I didn’t ask for your food.");
        append_dialogue(head, 0, "D-don’t get used to this or anything! I just had leftovers!");
        append_dialogue(head, 1, "Fine! Starve then, you ungrateful idiot!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20; 
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20; 
        prev_dialogue(&head);

        // Park 
        head = create_dialogue("Hey! You’re late! I’ve been waiting for—er, not like I was waiting for you or anything! I just happened to be here!");
        dialogue_list[2] = head;
        create_choice(head, 0, "Sorry, I didn’t mean to keep you waiting. Let’s enjoy the park together.");
        create_choice(head, 1, "If you weren’t waiting for me, why are you upset?");
        append_dialogue(head, 0, "T-together?! F-fine, but only because I have nothing better to do!");
        append_dialogue(head, 1, "I’m not upset! You’re just imagining things, idiot!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20; 
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20; 
        prev_dialogue(&head);
        
        // Classroom 
        head = create_dialogue("H-hey! You dropped your pen. Here, take it! It’s not like I wanted to help or anything. Just don’t litter.");
        dialogue_list[3] = head;
        create_choice(head, 0, "Thanks for noticing. You’re pretty observant.");
        create_choice(head, 1, "I didn’t ask for your help, but okay.");
        append_dialogue(head, 0, "W-whatever! It’s not a big deal, so don’t make it weird!");
        append_dialogue(head, 1, "Ugh, next time I’ll just leave it on the floor, you ungrateful idiot!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20; 
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20; 
        prev_dialogue(&head);

        // Cafeteria Scene
        head = create_dialogue("I-I only came here because it’s nice weather! Don’t think I’m here to hang out with you or anything!");
        dialogue_list[4] = head;
        create_choice(head, 0, "Sure, let’s just enjoy the weather together then.");
        create_choice(head, 1, "You don’t have to keep making excuses, you know.");
        append_dialogue(head, 0, "F-fine! Just don’t be annoying, alright? This is my quiet time!");
        append_dialogue(head, 1, "W-what excuses?! You’re so full of yourself! Idiot!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20; 
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20; 
        prev_dialogue(&head);

        // Park Scene 
        head = create_dialogue("H-hey! Are you seriously going to trip over every branch? You’re hopeless! Here, hold my hand so you don’t fall. N-not that I want to or anything!");
        dialogue_list[5] = head;
        create_choice(head, 0, "Thanks, I’ll try not to slow you down.");
        create_choice(head, 1, "I don’t need your help! I can manage on my own.");
        append_dialogue(head, 0, "J-just don’t make a big deal out of it! It’s not like I want to hold your hand or anything...");
        append_dialogue(head, 1, "Tch! Fine! Go ahead and fall flat on your face, idiot!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20; 
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20; 
        prev_dialogue(&head);

        // Classroom Scene 
        head = create_dialogue("H-hey! You forgot to hand in your homework, didn’t you? I-I only reminded you because it’s pathetic watching you panic last minute!");
        dialogue_list[6] = head;  
        create_choice(head, 0, "Thanks for the reminder! I’ll turn it in right away.");  
        create_choice(head, 1, "Why do you even care? Mind your own business.");  
        append_dialogue(head, 0, "G-good! Now hurry up before the teacher notices, idiot.");  
        append_dialogue(head, 1, "Tch! Whatever, just don’t come crying to me if you get in trouble!");  

        next_dialogue(&head, 0);  
        head->intimacy_gain = 20;  
        prev_dialogue(&head);  

        next_dialogue(&head, 1);  
        head->intimacy_gain = -20;  
        prev_dialogue(&head);  

        // Park Scene 
        head = create_dialogue("H-hey! Watch where you’re walking! You almost stepped on that flower! I-it’s not like I care about flowers, but be careful, idiot!");  
        dialogue_list[7] = head;  
        create_choice(head, 0, "Thanks for the warning. You’re surprisingly considerate.");  
        create_choice(head, 1, "It’s just a flower. Why are you overreacting?");  
        append_dialogue(head, 0, "S-surprisingly?! Hmph, don’t act so shocked! I’m not heartless, you know.");  
        append_dialogue(head, 1, "Ugh! If you’re going to act so careless, maybe you should just stay home!");  

        next_dialogue(&head, 0);  
        head->intimacy_gain = 20;  
        prev_dialogue(&head);  

        next_dialogue(&head, 1);  
        head->intimacy_gain = -20;  
        prev_dialogue(&head);  

        // Cafeteria Scene
        head = create_dialogue("I-I only came out here because it’s boring at home! It’s not like I wanted to run into you or anything!");  
        dialogue_list[8] = head;  
        create_choice(head, 0, "Well, since you’re here, let’s enjoy the cafeteria together.");  
        create_choice(head, 1, "If you didn’t want to see me, why are you talking to me?");  
        append_dialogue(head, 0, "F-fine! But don’t think this means I like hanging out with you or anything!");  
        append_dialogue(head, 1, "Tch! I-I wasn’t talking to you! You’re just imagining things, idiot!");  

        next_dialogue(&head, 0);  
        head->intimacy_gain = 25;  
        prev_dialogue(&head);  

        next_dialogue(&head, 1);  
        head->intimacy_gain = -20;  
        prev_dialogue(&head);

        // Classroom Scene
        head = create_dialogue("H-hey! You dropped your notebook. Here, take it! It’s not like I wanted to help or anything. Just don’t litter!");
        dialogue_list[9] = head;
        create_choice(head, 0, "Thanks for noticing. You’re pretty observant.");
        create_choice(head, 1, "I didn’t ask for your help, but okay.");
        append_dialogue(head, 0, "W-whatever! It’s not a big deal, so don’t make it weird!");
        append_dialogue(head, 1, "Ugh, next time I’ll just leave it on the floor, you ungrateful idiot!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);

        // Cafeteria Scene
        head = create_dialogue("I-I only sat here because everywhere else is full! Don’t think I wanted to sit with you or anything!");
        dialogue_list[10] = head;
        create_choice(head, 0, "That’s fine. Let’s enjoy lunch together.");
        create_choice(head, 1, "You don’t have to explain yourself. It’s okay.");
        append_dialogue(head, 0, "F-fine! Just don’t make it awkward or anything!");
        append_dialogue(head, 1, "W-what do you mean ‘it’s okay’? You’re so full of yourself, idiot!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);

        // Park Scene
        head = create_dialogue("H-hey! Watch where you’re walking! You almost stepped in that puddle! Are you always this clumsy?");
        dialogue_list[11] = head;
        create_choice(head, 0, "Thanks for the warning. I’ll be more careful.");
        create_choice(head, 1, "I’m fine. You don’t need to worry about me.");
        append_dialogue(head, 0, "G-good! Just don’t make me have to save you again!");
        append_dialogue(head, 1, "Tch! Fine, trip into a puddle next time. See if I care, idiot!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);

        // Classroom Scene
        head = create_dialogue("H-hey! You’re late! It’s not like I was waiting for you or anything. I just noticed the time, that’s all!");
        dialogue_list[12] = head;
        create_choice(head, 0, "Thanks for noticing. I’ll try to be on time next time.");
        create_choice(head, 1, "Why do you care if I’m late?");
        append_dialogue(head, 0, "W-whatever! Just don’t make it a habit or anything!");
        append_dialogue(head, 1, "I-I don’t care! I was just making an observation, idiot!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);

        // Cafeteria Scene
        head = create_dialogue("H-hey! You ordered the same thing as me? Copycat! It’s not like I care, though...");
        dialogue_list[13] = head;
        create_choice(head, 0, "Guess we have the same good taste. Let’s enjoy it together.");
        create_choice(head, 1, "Relax, it’s just food. No big deal.");
        append_dialogue(head, 0, "F-fine! But don’t make it weird, okay?");
        append_dialogue(head, 1, "Tch! Whatever! Enjoy your bland taste, idiot!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);

        // Park Scene
        head = create_dialogue("H-hey! Don’t walk so fast! It’s not like I’m struggling to keep up or anything, I just wanted to enjoy the scenery!");
        dialogue_list[14] = head;
        create_choice(head, 0, "Alright, let’s slow down and enjoy it together.");
        create_choice(head, 1, "You can just say you’re tired, you know.");
        append_dialogue(head, 0, "G-good! This is a nice place, after all!");
        append_dialogue(head, 1, "T-tired?! Who’s tired?! You’re so annoying sometimes, idiot!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);

        // Classroom Scene
        head = create_dialogue("H-hey! You forgot your homework! I-I didn’t bring it because I care or anything! I just didn’t want the teacher to yell at you!");
        dialogue_list[15] = head;
        create_choice(head, 0, "Thanks for looking out for me. I owe you one.");
        create_choice(head, 1, "I would’ve been fine without it, but thanks anyway.");
        append_dialogue(head, 0, "W-whatever! Just don’t forget it next time, okay?");
        append_dialogue(head, 1, "Tch! If you don’t care, maybe I won’t bother next time, idiot!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);

        // Cafeteria Scene
        head = create_dialogue("H-hey! I noticed you didn’t grab a drink. Here, take mine. It’s not like I wanted to share or anything, I just had an extra!");
        dialogue_list[16] = head;
        create_choice(head, 0, "That’s really kind of you. Thanks!");
        create_choice(head, 1, "I’m fine, but thanks for the offer.");
        append_dialogue(head, 0, "I-it’s nothing! Just drink it and don’t say weird things!");
        append_dialogue(head, 1, "F-fine! If you don’t want it, I’ll just keep it for myself!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);

        // Park Scene
        head = create_dialogue("H-hey! You’re staring off into space! Watch where you’re walking, or you’ll trip over something!");
        dialogue_list[17] = head;
        create_choice(head, 0, "Thanks for the heads-up. I’ll be more careful.");
        create_choice(head, 1, "I can manage myself. You don’t need to worry.");
        append_dialogue(head, 0, "G-good! Just don’t make me have to save you again!");
        append_dialogue(head, 1, "Tch! Fine, fall over if you want! See if I care, idiot!");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
	}

    else if (strcmp(heroine_name, "Azure") == 0) {
        
        //---------------first ever dialogue-----------------
        head = create_dialogue("Good morning! Don't you ever just think that orange and blue make such a good artwork in the sky?");
        dialogue_list[0] = head;

        create_choice(head, 0, "Right? Early mornings are always beautiful.");
        create_choice(head, 1, "What? You always talk weird.");

        append_dialogue(head, 0, "Such a splendid background should also have a splendid muse. Will you be my muse?");
        append_dialogue(head, 1, "Hmp! I should learn not to expect much from normal people.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "I would be honored.");
        create_choice(head, 1, "I would have to pass. I'm busy.");
        
        append_dialogue(head, 0, "Wonderful! I will be expecting you in the near future.");
        append_dialogue(head, 1, "Oh...next time I hope?");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*chuckles* And who says I'm normal?");
        create_choice(head, 1, "*snorts* Maybe you should learn to talk normal.");
        
        append_dialogue(head, 0, "Oh? Are you suggesting that your weird too?");
        append_dialogue(head, 1, "*gasps in offended* And you should learn to have manners. *walk out*");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Nope, that I'm splendid enough to catch an artist's eye. *wink*");
        create_choice(head, 1, "Not as weird as you though. *big laugh*");
        
        append_dialogue(head, 0, "*laughs* I guess I have an eye for that. Would you mayhaps be willing to be my model sometime?");
        append_dialogue(head, 1, "*gasps in offended* Such mannerless behavior. walk out");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "I would be honored.");
        create_choice(head, 1, "Oh I'm sorry. I'm busy.");
        
        append_dialogue(head, 0, "Wonderful! See you around then.");
        append_dialogue(head, 1, "Oh that's a shame. Next time then?");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        //40 intimacy convo
        
        head = create_dialogue("Oh! It's such a surprise seeing you here!");
        dialogue_list[1] = head;

        create_choice(head, 0, "Right?");
        create_choice(head, 1, "Hmm? It's not really. I go here a lot.");

        append_dialogue(head, 0, "Would you, perhaps, mind the idea of dining with me today?");
        append_dialogue(head, 1, "Ah...would you mind if I dined with you today?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Nah, go ahead.");
        create_choice(head, 1, "Oh I mind. A lot.");
        
        append_dialogue(head, 0, "*One eventful meal later*\n\tThank you for dining with me today. I'm so happy that we got to converse a lot.");
        append_dialogue(head, 1, "Oh...I'll leave you alone then.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "It's no problem really. I had a lot of fun talking with you too.");
        create_choice(head, 1, "Your welcome! Now you know a lot about me. *laughs*");
        
        append_dialogue(head, 0, "We really should do this again sometime soon.");
        append_dialogue(head, 1, "*laughs* Well the sentiment is mutual. See you around?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Sure! next time then?");
        create_choice(head, 1, "Eh, if fate allows it. *laughs*");
        
        append_dialogue(head, 0, "Yeah, next time it is. waves goodbye");
        append_dialogue(head, 1, "*laughs* Then I'll hope that fate would allow it. See you soon. *waves goodbye*");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Not really. Go ahead.");
        create_choice(head, 1, "Oh, I would mind actually.");
        
        append_dialogue(head, 0, "*One eventful meal later*\nThank you for dining with me today. I'm so happy that we got to converse a lot.");
        append_dialogue(head, 1, "Oh...I'll leave you alone then.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "It's no problem really. I had a lot of fun talking with you too.");
        create_choice(head, 1, "Your welcome! Now you know a lot about me. *laughs*");
        
        append_dialogue(head, 0, "We really should do this again sometime soon.");
        append_dialogue(head, 1, "*laughs* Well the sentiment is mutual. See you around?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Sure! next time then?");
        create_choice(head, 1, "Eh, if fate allows it. laughs");
        
        append_dialogue(head, 0, "Yeah, next time it is. waves goodbye");
        append_dialogue(head, 1, "*laughs* Then I'll hope that fate would allow it. See you soon. *waves goodbye*");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        
        //60 intimacy convo
        
        head = create_dialogue("Oh! it is so nice seeing you again unexpectedly.");
        dialogue_list[2] = head;
        
        create_choice(head, 0, "*laughs* It seems like fate really wants for us to meet.");
        create_choice(head, 1, "Are you sure you're not following me? *laughs*");
        
        append_dialogue(head, 0, "I guess fate really wants for you to be my muse. Are you free perhaps.");
        append_dialogue(head, 1, "Oh? Of course not. *laughs* Would you mind the idea of being my muse today?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah actually. I guess I'm your muse for today.");
        create_choice(head, 1, "If you pay me I might think about it.");
        
        append_dialogue(head, 0, "Splendid! Strike a pose and let the artist do its magic.");
        append_dialogue(head, 1, "Oh...does monetary sum really matter that much to you?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "My artistic debut is in your hands. *salutes*");
        create_choice(head, 1, "I hope you can draw all of this gorgeousness. *laughs*");
        
        append_dialogue(head, 0, "Have faith, your in great hands.\n*A few hours later*\nWhat do you think?");
        append_dialogue(head, 1, "Have faith, your in great hands.\n*A few hours later*\nWhat do you think?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Damn! Your good.");
        create_choice(head, 1, "Wow...you wasted my time...for this?");
        
        append_dialogue(head, 0, "Thank you for such a high complement. I would like for you to keep it. If you don't mind?");
        append_dialogue(head, 1, "*gasps in offended* I'm terrably sorry then. *walks out*");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Really? I would love too.");
        create_choice(head, 1, "*laughs* Nah, I would rather not.");
        
        append_dialogue(head, 0, "Here you go. see you soon then. *waves goodbye*");
        append_dialogue(head, 1, "Oh...I'm sorry it wasn't up to your standards.");
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Nah your good. I'm sure it will be better next time.");
        create_choice(head, 1, "Oh I'm glad you know.");
        
        append_dialogue(head, 0, "Okay, next time then. *awkwardly waves goodbye*");
        append_dialogue(head, 1, "Hmp! Still mannerless. *walks out*");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 0;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "I'm just kidding. *strikes a pose* Draw me, go on.");
        create_choice(head, 1, "Of course. Nothing is free nowadays.");
        
        append_dialogue(head, 0, "*sigh of relief* Okay, stay still.\n*A few hours later*\nWhat do you think?");
        append_dialogue(head, 1, "Oh...then I won't take up much more of your time. *walks away*");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Damn! Your good.");
        create_choice(head, 1, "Wow...you wasted my time...for this?");
        
        append_dialogue(head, 0, "Thank you for such a high complement. I would like for you to keep it. If you don't mind?");
        append_dialogue(head, 1, "*gasps in offended* I'm terrably sorry then. *walks out*");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Really? I would love too.");
        create_choice(head, 1, "*laughs* Nah, I would rather not.");
        
        append_dialogue(head, 0, "Here you go. see you soon then. *waves goodbye*");
        append_dialogue(head, 1, "Oh...I'm sorry it wasn't up to your standards.");
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Nah your good. I'm sure it will be better next time.");
        create_choice(head, 1, "Oh I'm glad you know.");
        
        append_dialogue(head, 0, "Okay, next time then. *awkwardly waves goodbye*");
        append_dialogue(head, 1, "Hmp! Still mannerless. *walks out*");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 0;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Not reall. I've got time to spare.");
        create_choice(head, 1, "Me? As your muse? Dream on. *laughs*");
        
        append_dialogue(head, 0, "Oh thank you so much! Pose however you desire, I'll just prepare my materials.");
        append_dialogue(head, 1, "Oh...I believe it is time for you to leave.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*strikes a pose* Is this good enough?");
        create_choice(head, 1, "Just draw me however you want. I don't really care.");
        
        append_dialogue(head, 0, "Yes yes! More than enough. Stay still please.\n*A few hours later*\nWhat do you think?");
        append_dialogue(head, 1, "Oh...I believe we should just try this another time. *walks away*");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Damn! Your good.");
        create_choice(head, 1, "Wow...you wasted my time...for this?");
        
        append_dialogue(head, 0, "Thank you for such a high complement. I would like for you to keep it. If you don't mind?");
        append_dialogue(head, 1, "*gasps in offended* I'm terrably sorry then. *walks out*");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Really? I would love too.");
        create_choice(head, 1, "*laughs* Nah, I would rather not.");
        
        append_dialogue(head, 0, "Here you go. see you soon then. *waves goodbye*");
        append_dialogue(head, 1, "Oh...I'm sorry it wasn't up to your standards.");
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Nah your good. I'm sure it will be better next time.");
        create_choice(head, 1, "Oh I'm glad you know.");
        
        append_dialogue(head, 0, "Okay, next time then. *awkwardly waves goodbye*");
        append_dialogue(head, 1, "Hmp! Still mannerless. *walks out*");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 0;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        
        //80 intimacy convo
        
        head = create_dialogue("Oh! I see fate has decided for us to meet again.");
        dialogue_list[3] = head;
        
        create_choice(head, 0, "Right? I'm starting to believe it's destiny.");
        create_choice(head, 1, "*laughs* At this point might as well be attached to the hip");
        
        append_dialogue(head, 0, "Oh that would be increadible. I truly do think that we complement each other a lot.");
        append_dialogue(head, 1, "*laughs* I feel like I know you enough for that to be possible.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Same, I also think we make a great pair.");
        create_choice(head, 1, "Right? It just feels like we were made for each other.");
        
        append_dialogue(head, 0, "Oh what would you think if I arranged a date for us sometime?.");
        append_dialogue(head, 1, "You really think so?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "A date? Seriously? With me?");
        create_choice(head, 1, "I would love too, honestly.");
        
        append_dialogue(head, 0, "Yes, if you don't mind?");
        append_dialogue(head, 1, "Oh amazing! See you soon then. *waves goodbye*");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yes! I would love too.");
        create_choice(head, 1, "Duh! A friendly date would be so fun!");
        
        append_dialogue(head, 0, "Oh amazing! I'll see you soon then. *waves goodbye*");
        append_dialogue(head, 1, "Oh...I guess were not on the same page then. *walks out*");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -60;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Duh! My heart won't beat this fast if I don't think so.");
        create_choice(head, 1, "We're basically soulmates.");
        
        append_dialogue(head, 0, "Oh please tell me you won't mind going on a date with me?");
        append_dialogue(head, 1, "If we're soulmates then you are also thinking about us going on a date sometime right?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Of course I won't mind.");
        create_choice(head, 1, "I would love to go on a date with you.");
        
        append_dialogue(head, 0, "Oh amazing! See you soon then. *waves goodbye*");
        append_dialogue(head, 1, "Oh amazing! See you soon then. *waves goodbye*");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "See? We really are soulmates.");
        create_choice(head, 1, "Huh...I guess were not soulmates then. That was so far off.");
        
        append_dialogue(head, 0, "Whaa amazing! I'll see you soon then.*waves goodbye*");
        append_dialogue(head, 1, "Oh...I guess we're not on the same page then. *walks out*");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -60;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Right? Like siblings from another parent.");
        create_choice(head, 1, "Your basically my best friend at this point.");
        
        append_dialogue(head, 0, "Oh...you see me as a sibling?");
        append_dialogue(head, 1, "I'm...your best friend?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah. Your like the sister I never had.");
        create_choice(head, 1, "Of course. Your family at this point.");
        
        append_dialogue(head, 0, "Oh...I guess were not on the same page then. *walks out*");
        append_dialogue(head, 1, "Like...platonic family?");
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Is there a different kind?");
        create_choice(head, 1, "Duh? Did you expect something else?");
        
        append_dialogue(head, 0, "Huh...I have to go now. See you soon then. *walks out*");
        append_dialogue(head, 1, "What? I guess it was only me then. *dissapointed exhale*");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = -20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -80;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 0);
        head->intimacy_gain = -60;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Duh? What else would you be?");
        create_choice(head, 1, "Yeah. The bestest most creative best friend.");
        
        append_dialogue(head, 0, "Oh...I guess we're not on the same page then. *walks out*");
        append_dialogue(head, 1, "Ah I see. I need to go now, see you soon best friend. *awkwardly waves goodbye*");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = -60;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = -40;
        prev_dialogue(&head);
        
        
        //100 intimacy convo
        
        head = create_dialogue("Oh your here already. Did you wait long?");
        dialogue_list[4] = head;
        
        create_choice(head, 0, "No, I just got here too.");
        create_choice(head, 1, "Don't worry about it.");
        
        append_dialogue(head, 0, "Oh good. Thank you for agreeing to this date. I really appreciate it.");
        append_dialogue(head, 1, "Thank you for planning this date really, I appreciate it greatly.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "It's my pleasure really.");
        create_choice(head, 1, "Of course. A date with you is worth it.");
        
        append_dialogue(head, 0, "Let's go start our date already. *laughs*");
        append_dialogue(head, 1, "Oh your making me turn red. Let's go?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, let's go.");
        create_choice(head, 1, "*laughs* Where to?");
        
        append_dialogue(head, 0, "*Few hours later*\nOh that was so fun! We should do this again sometime.");
        append_dialogue(head, 1, "Hmm...let's go there first, come on.\n*Few hours later*\nOh that was so fun! We should do this again sometime.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, I had a great time too.");
        create_choice(head, 1, "Sure! I would love too.");
        
        append_dialogue(head, 0, "Uhm...I would like to ask something?");
        append_dialogue(head, 1, "Uhm...I would like to ask something?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Yeah, I had a great time too.");
        create_choice(head, 1, "Sure! I would love too.");
        
        append_dialogue(head, 0, "Uhm...I would like to ask something?");
        append_dialogue(head, 1, "Uhm...I would like to ask something?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Yeah, let's go.");
        create_choice(head, 1, "*laughs* Where to?");
        
        append_dialogue(head, 0, "*Few hours later*\nOh that was so fun! We should do this again sometime.");
        append_dialogue(head, 1, "Hmm...let's go there first, come on.\n*Few hours later*\nOh that was so fun! We should do this again sometime.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, I had a great time too.");
        create_choice(head, 1, "Sure! I would love too.");
        
        append_dialogue(head, 0, "Uhm...I would like to ask something?");
        append_dialogue(head, 1, "Uhm...I would like to ask something?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Yeah, I had a great time too.");
        create_choice(head, 1, "Sure! I would love too.");
        
        append_dialogue(head, 0, "Uhm...I would like to ask something?");
        append_dialogue(head, 1, "Uhm...I would like to ask something?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Your welcome. Let's go?");
        create_choice(head, 1, "It's the least I can do really.");
        
        append_dialogue(head, 0, "Yeah let's go.\n*Few hours later*\nOh that was so fun! We should do this again sometime.");
        append_dialogue(head, 1, "Aww that's so sweet of you.\n*Few hours later*\nOh that was so fun! We should do this again sometime.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, I had a great time too.");
        create_choice(head, 1, "Sure! I would love too.");
        
        append_dialogue(head, 0, "Uhm...I would like to ask something?");
        append_dialogue(head, 1, "Uhm...I would like to ask something?");
        
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Yeah, I had a great time too.");
        create_choice(head, 1, "Sure! I would love too.");
        
        append_dialogue(head, 0, "Uhm...I would like to ask something?");
        append_dialogue(head, 1, "Uhm...I would like to ask something?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Yeah, let's go.");
        create_choice(head, 1, "*laughs* Where to?");
        
        append_dialogue(head, 0, "*Few hours later*\nOh that was so fun! We should do this again sometime.");
        append_dialogue(head, 1, "Hmm...let's go there first, come on.\n*Few hours later*\nOh that was so fun! We should do this again sometime.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, I had a great time too.");
        create_choice(head, 1, "Sure! I would love too.");
        
        append_dialogue(head, 0, "Uhm...I would like to ask something?");
        append_dialogue(head, 1, "Uhm...I would like to ask something?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Yeah, I had a great time too.");
        create_choice(head, 1, "Sure! I would love too.");
        
        append_dialogue(head, 0, "Uhm...I would like to ask something?");
        append_dialogue(head, 1, "Uhm...I would like to ask something?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "Oh uhm okay, ask away.");
        create_choice(head, 1, "Go ahead.");
        
        append_dialogue(head, 0, "I really like you. Would you be my lover?");
        append_dialogue(head, 1, "I really like you. Would you be my lover?");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*coughs violently* Damn, that fast?");
        create_choice(head, 1, "Whoa...I was going to ask if I can court you.");
        
        append_dialogue(head, 0, "Oh I'm so sorry. Too fast?");
        append_dialogue(head, 1, "Of course you can court me. Awww~ your so sweet.");
        
        next_dialogue(&head, 0);
        
        create_choice(head, 0, "Yeah, It was. *laughs*");
        create_choice(head, 1, "Yeah, let's slow down okay?");
        
        append_dialogue(head, 0, "*laughs* Then let's take it slow.");
        append_dialogue(head, 1, "*laughs* Then let's take it slow.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        
        create_choice(head, 0, "*laughs* Then I'm officially courting you starting today.");
        create_choice(head, 1, "*laughs* Then let's get to know each other better.");
        
        append_dialogue(head, 0, "Whaa~ I can't believe your officially my suitor. *gi-kilig*");
        append_dialogue(head, 1, "*giggles* Okay, I would love that.");
        
        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);
        
    }

    else if (strcmp(heroine_name, "Nadia") == 0) {
        head = create_dialogue("Hi there, Good Morning *smiles*");
        dialogue_list[0] = head;

        create_choice(head, 0, "Hello, Good Morning to you too (is'nt this Nadia, who's a volleyball player in our school) *smiles*");
        create_choice(head, 1, "Yeah hello *uninterested*");
        append_dialogue(head, 0, "The sun this morning is beautiful, its really a good weather to have a light walk *smiles*");
        append_dialogue(head, 1, "ahh, okay *disappointed*");


        next_dialogue(&head, 0);



        create_choice(head, 0, "It's very beautiful, just like you Nadia *smiles*");
        create_choice(head, 1, "No, its just the same as usual");
        append_dialogue(head, 0, "Your a sweet talker huh?, how about we go for a walk? *smiles*");
        append_dialogue(head, 1, "Ah okay, is that how you see huh? *disappointed*");


        next_dialogue(&head, 0);

        create_choice(head, 0, "No, not at all, I'm just telling a fact, and did I hear that right?, you wanna go walk with me? *confused*");
        create_choice(head, 1, "Yes it is, is there anything you want? cause, if that's all, I'm gonna get going");
        append_dialogue(head, 0, "*Blushing* (face is getting red) You did hear is right, I wanna go walk with you and Thank you, your the first person that compliments my beauty, shall we go?, for our walk *smiles*");
        append_dialogue(head, 1, "No, that's all *disappointed*");


        next_dialogue(&head, 0);
        head->intimacy_gain = 0;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = 0;
        prev_dialogue(&head);

        head->intimacy_gain = 0;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = 0;
        prev_dialogue(&head);





        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -10;
        prev_dialogue(&head);

        //---------------------------------------------------------------------------------------------------
        head = create_dialogue("*thuds* Ahh, sorry, I didn't mean to bump into you *apologizing sincerely* ");
        dialogue_list[1] = head;

        create_choice(head, 0, "Nadia?, good to see again, and dont worry, am at fault too, I didn't pay attention on the way I'm going *smiles*");
        create_choice(head, 1, "You again why do I get entangled up with you lately?, just be careful next time okay *snobs* ");
        append_dialogue(head, 0, "Uhmm, are you really okay?, I'm really sorry, how about I treat you for lunch? ");
        append_dialogue(head, 1, "*snobs* I'm really sorry, I really didn't mean to bump into you");

        next_dialogue(&head, 0);


        create_choice(head, 0, "Well if your really insist of treating me, why not?, but the drinks is on me, how about that?");
        create_choice(head, 1, "Uhhhg just stay out of my sight");
        append_dialogue(head, 0, "Lets do that then, let;s go I'm already starving *smiles*");
        append_dialogue(head, 1, "What wrong with you?, I already apologize, can't you just forgive me or just be calm? *walks out*");

        next_dialogue(&head, 0);
        head->intimacy_gain = 0;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = 0;
        prev_dialogue(&head);

        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -10;
        prev_dialogue(&head);



        //-------------------------------------------------------------------------------
        head = create_dialogue("*catching her breath* Hah Hah Hah, 10 laps to go");
        dialogue_list[2] = head;
        create_choice(head, 0, "Hey!!!, Nadia, good to see you again, hmm? are you training?, you really working hard huh?");
        create_choice(head, 1, "*ignore and walkaway*");
        append_dialogue(head, 0, "Hi, Good to see you too, Yes I need to work hard because we have an upcoming tournament, by the way were are you going?");
        append_dialogue(head, 1, "Huh?, why does he ignore me?, what's wrong with him?");

        next_dialogue(&head, 0);


        create_choice(head, 0, "I'm just gonna find some quite place with good scenery for me to study, cause I really need to improve my grades in chemistry, and Good Luck on your game Nadia");
        create_choice(head, 1, "(does this girl has anything to say to me?, uhh never mind, I'm just gonna go and study");
        append_dialogue(head, 0, "Thank you, I really appreciate that, but I will appreciate it more if you will watch and cheer for us *smile with a pleasing eyes*");
        append_dialogue(head, 1, "What;s with him did I do something wrong?");

        next_dialogue(&head, 0);

        create_choice(head, 0, "Well, Nadia for you I will go and cheer you on your game, I will your biggest fan (who can refuse, if your that cute Nadia, she's so cute) *smiles*");
        create_choice(head, 1, "Sorry but I have plans, maybe next time Nadia");
        append_dialogue(head, 0, "Yey, thank you, so then, I'll see you there okay *smiles happily*");
        append_dialogue(head, 1, "Ahh,okay, that's so sad *disappointed*");

        next_dialogue(&head, 0);
        head->intimacy_gain = 0;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = 0;
        prev_dialogue(&head);
        head->intimacy_gain = 0;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = 0;
        prev_dialogue(&head);

        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -10;
        prev_dialogue(&head);

        // ------------------------------------------------------------------------------------

        head = create_dialogue("(Laying in bed) Ahhhhh, I'm so bored right now, there's nothing to do, Hmm, how about, I will talk to someones *smiles*");
        dialogue_list[3] = head;
        create_choice(head, 0, "(Phone rings) **Hmm?, is'nt this Nadia?, I didn't expect her to chat me, I should reply** Hello Nadia, Good Evening, How can I help you?");
        create_choice(head, 1, "(Phone rings) Huh?, isn't this Nadia?, why would she chat me?, uhh susch a nuisance, Hello, what do you want?");
        append_dialogue(head, 0, "Good Evening to you too, to be honest I'm really bored right now, I need someone to talk too, and I think that someone is you, but am I not disturbing you right?, if not could you accompany me tonight? *blushing*");
        append_dialogue(head, 1, "Good Evening, did I disturb you?, I'm really bored right now, can we talk?");

        next_dialogue(&head, 0);

        create_choice(head, 0, "Me too Nadia, I'm just laying in my bed, and I'm so bored too, and you did not disturb me Nadia, its alway my pleasure to accompany you , if you want I will accompany you forever *smirks and smiles*");
        create_choice(head, 1, "Yes, you did disturb me, just talk to your friends or family, so please do not disturb me again *turn off the phone*");
        append_dialogue(head, 0, "*Face is getting red* You idiot, stop teasing me( did he really mean that?), so what are plan this weekend?");
        append_dialogue(head, 1, "oh sorry (he could just say no, why get so angry?, how rude) *disappointed* ");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -10;
        prev_dialogue(&head);

        head->intimacy_gain = 0;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = 0;
        prev_dialogue(&head);
        //-----------------------------------------------------------------------------------
        head = create_dialogue("(walking towards the academy lobby) Another day at school ** I hope I can see him today** ");
        dialogue_list[4] = head;
        create_choice(head, 0, "( looking in the phone) Ahh, its already 8, I'm so late in my first subject *clash* ouch.");
        create_choice(head, 1, "( looking in the phone) Ahh, its already 8, I'm so late in my first subject *clash* ouch.");
        append_dialogue(head, 0, "Ahh, ouch (drops the books)");
        append_dialogue(head, 1, "Ahh, ouch (drops the books)");

        next_dialogue(&head, 0);

        create_choice(head, 0, "(pick'ups Nadia's books) I'm really sorry miss, I didn't see you, cause I'm in a hurry, and I was looking at my phone and didn't pay attention on the way (handing the book) Huh?, Nadia? * he didn't know that Nadia is the one he bumped with*");
        create_choice(head, 1, "Ahhh, such a mess, why are you blocking the way huh?");
        append_dialogue(head, 0, "You?, we meet again ( is this fate the we bump on each other?) *blush* about what happen, just forget it okay, I'm fine, and I understand, your in a hurry but be careful next time okay *smiles* ");
        append_dialogue(head, 1, "Huh?, why are you so mad?, your the one who bump into me?");

        next_dialogue(&head, 0);

        create_choice(head, 0, "Really?, thank you Nadia, as for the compensation for the trouble, I'll treat you a lunch next time, for now I gotta go I have a class to attend, bye Nadia");
        create_choice(head, 1, "What?, uhh just forget it, I'm gonna go, I have a class to attend to *running*");
        append_dialogue(head, 0, "Okay *smiles*, I look forward of seeing you again");
        append_dialogue(head, 1, "Huh? so thats it?, thanks for ruining my day (such a rude person)");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);

        head->intimacy_gain = 0;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = 0;
        prev_dialogue(&head);

        head->intimacy_gain = 0;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = 0;
        prev_dialogue(&head);
        //-----------------------------------------------------------------------------------
        head = create_dialogue("*Running* Ha Ha Ha, hooo, 2 more laps ");
        dialogue_list[5] = head;
        create_choice(head, 0, "Hmm?, Nadia?, hello, Good to see you");
        create_choice(head, 1, "She's running again huh?, well, what do I care?*ignores and leave ");
        append_dialogue(head, 0, "Hi, Good too see you too **what the hell is wrong with this guy, he's ignoring me all the time, then now showing affection to me?**");
        append_dialogue(head, 1, "What a cold hearted guy, I should keep my distance to that guy *started to run again*");

        next_dialogue(&head, 0);
        head->intimacy_gain = -20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);



        head = create_dialogue("Hey, why so cold?, am I not beautiful?");
        dialogue_list[6] = head;
        create_choice(head, 0, "Sorry my bad, I didn't meant to treat you coldly, and Miss, you so are beautiful like  the sunset this morning ");
        create_choice(head, 1, "What's wrong with that?, I didn't know you, and yes your not beautiful, sorry");
        append_dialogue(head, 0, "Thank you, I really appreciate that, and call me Nadia *smile*");
        append_dialogue(head, 1, "Did no one tell you that girl's like complements, what with the attitude?, did I do something wrong to you? *confused*");

        next_dialogue(&head, 0);
        head->intimacy_gain = 30;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -10;
        prev_dialogue(&head);




        head = create_dialogue("Hey, I already apologize, and it was an accident so its not really that kind of a big deal to get angry like that *confused*");
        dialogue_list[7] = head;
        create_choice(head, 0, "Sorry my bad, I just got carried away by my emotions, please for give me");
        create_choice(head, 1, "What accident?  it is clearly your fault");
        append_dialogue(head, 0, "It's okay, I understand, try to calm down next time okay");
        append_dialogue(head, 1, "What??, it was an accident, please try to calm down **this guy  really needs to work on his anger management**");

        next_dialogue(&head, 0);
        head->intimacy_gain = 30;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -10;
        prev_dialogue(&head);




        head = create_dialogue("Hey wait, whats wrong with you why are ignoring me all of a sudden? *confused*");
        dialogue_list[8] = head;
        create_choice(head, 0, "Sorry, I actually don't want to disturb you on your training Nadia *smile*");
        create_choice(head, 1, "Huh? why would I not ignore you?, were not that close");
        append_dialogue(head, 0, "Ahh, well I'm on a break, and I'm really surprised, your so considerate ");
        append_dialogue(head, 1, "Are we? were friends, so why would you ignore me? *sad*");

        next_dialogue(&head, 0);
        head->intimacy_gain = 30;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -10;
        prev_dialogue(&head);



        head = create_dialogue("But like I said I don;t have anyone to talk too, they are all busy");
        dialogue_list[9] = head;
        create_choice(head, 0, "Okay Nadia, I will talk to you,by the way, what date does your tournament start?");
        create_choice(head, 1, "Then?, why do I care, huh?, like I said to talk to you, so bye(turn off the phone)");
        append_dialogue(head, 0, "Yey, thank you, and my tournament well be on January 11, this saturday");
        append_dialogue(head, 1, "okay, sorry for bothering you *sad*");

        next_dialogue(&head, 0);
        head->intimacy_gain = 30;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -10;
        prev_dialogue(&head);








    }
    return dialogue_list;
}

//recursive iteration
int use_dialogue(Heroine* heroine, Dialogue* dialogue, char* header_str) {
    char input;
    int gain;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    gain = dialogue->intimacy_gain;

    printf(header_str);
    render_img(heroine->images[0], columns, 138);

    printf("\n");
    printf("%.*s\n", columns, "======================================================================================================================================================================");
    printf("\n");

    printf("%s: %s\n", heroine->name, dialogue->text);
    printf("\n");
    printf("%.*s\n", columns, "======================================================================================================================================================================");

    if (dialogue->child_dialogues[0] != NULL && dialogue->child_dialogues[1]  != NULL) {


        printf("X: %s\n", dialogue->choices[0]);
        printf("Y: %s\n\n", dialogue->choices[1]);
        printf("choice: ");
        scanf(" %c", &input);

        switch (tolower(input)) {
            case 'x':
                dialogue = dialogue->child_dialogues[0];
                break;

            case 'y':
                dialogue = dialogue->child_dialogues[1];
                break;

            default:
                printf("input does not match any of the choices. Please try again.");
                getch();

                
        }

        system("cls");
        gain = gain + use_dialogue(heroine, dialogue, header_str);
    }

    return gain;
}


