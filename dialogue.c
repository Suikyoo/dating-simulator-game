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
        head = create_dialogue(" 'Hey, isn't that Mio?' \n 'I heard she made a freshman cry last time' \n *Bump* *Urgh* watch where you're going you idiot!");
        dialogue_list[0] = head;

        create_choice(head, 0, "I'm really sorry!");
        create_choice(head, 1, "You're the one who should watch where you're going!");
        append_dialogue(head, 0, "Hmph! You better watch out next time!");
        append_dialogue(head, 1, "So it's my fault now");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);

        //---------------------------------------------------------------------------------------------------
        head = create_dialogue("Hey! You're that idiot that bumped into me last time! Come here for a sec!");
        dialogue_list[1] = head;

        create_choice(head, 0, "Do I even know you?");
        create_choice(head, 1, "Uhm S-sure...");
        append_dialogue(head, 0, "You're such a shameless bastard! Just come here!");
        append_dialogue(head, 1, "Faster! You're wasting my time!");

        next_dialogue(&head, 0);

        create_choice(head, 0, "(ignore and walk away)");
        create_choice(head, 1, "*Tsk *hmph (gets closer)");
        append_dialogue(head, 0, "HEEYYY! I'm not even done talking to you!");
        append_dialogue(head, 1, "Hmph! Hey! What's your name by the way?");

        next_dialogue(&head, 0);
        head->intimacy_gain = -20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        prev_dialogue(&head);
        create_choice(head, 0, "W-wait, I'm coming!");
        create_choice(head, 1, "Can't you even wait??");
        append_dialogue(head, 0, "Hmph! That's good. What's your name by the way.");
        append_dialogue(head, 1, "Ugh! You're too slow! (rolls eyes and walks away)");

        next_dialogue(&head, 0);
        head->intimacy_gain = 20;
        prev_dialogue(&head);

        next_dialogue(&head, 1);
        head->intimacy_gain = -20;
        prev_dialogue(&head);

        //-------------------------------------------------------------------------------
		head = create_dialogue("Hey, loser! What are you doing here?");
		dialogue_list[2] = head;
		create_choice(head, 0, "You don't need to know the reason why I'm here");
		create_choice(head, 1, "I'm just doing an errand");
        append_dialogue(head, 0, "*Slap* Answer me properly");
        append_dialogue(head, 1, "I bet you have a lot of spare time. So, come help me wtih this this chore");
		
		next_dialogue(&head, 0);
		head->intimacy_gain = -20;
		prev_dialogue(&head);
		
		next_dialogue(&head, 1);
		head->intimacy_gain = 20;
		prev_dialogue(&head);

		// ------------------------------------------------------------------------------------
	
		head = create_dialogue("Hey you! You really messed up our work the other day with how sloppy you were! Hmph! Anyways, here's a cup of coffee. I got it for free.");
		dialogue_list[3] = head;
		create_choice(head, 0, "Well, I genuinely just wanted to help you.");
		create_choice(head, 1, "You should've done it yourself then!");
        append_dialogue(head, 0, "W-well, I didn't even need your help to begin with! you idiot!");
        append_dialogue(head, 1, "You were really just adding up to the work I needed to do.");
		
		next_dialogue(&head, 0);
		head->intimacy_gain = 20;
		prev_dialogue(&head);
		
		next_dialogue(&head, 1);
		head->intimacy_gain = -20;
		prev_dialogue(&head);
		//-----------------------------------------------------------------------------------
		head = create_dialogue("Hey idiot! I just won a raffle! It's a bit annoying winning two movie tickets though. Here. I'll give you the other ticket. It's not like I wanted to hang out with you or anything... hmph!");
		dialogue_list[4] = head;
		create_choice(head, 0, "I'm sorry. I'm busy with all these school works.");
		create_choice(head, 1, "You could've just said you wanted to hang out with me.");
        append_dialogue(head, 0, "Whatever! I mean, I could just go on my own! It's not like it's necessary!");
        append_dialogue(head, 1, "*Blush* W-what do you mean?? I'm just saying I had an extra ticket! A-anyways, I need to get going...(hands over the ticket)");
		
		next_dialogue(&head, 0);
		head->intimacy_gain = -20;
		prev_dialogue(&head);
		
		next_dialogue(&head, 1);
		head->intimacy_gain = 20;
		prev_dialogue(&head);
		//-----------------------------------------------------------------------------------
		head = create_dialogue("You again!??! How dare you show your face here?!?");
		dialogue_list[5] = head;
		create_choice(head, 0, "(Ignore)");
		create_choice(head, 1, "I'm really sorry! UwU");
        append_dialogue(head, 0, "*Sigh* (backs away) *Whoosh* (throws a punch) ... That will do!");
        append_dialogue(head, 1, "Hmph! Look at you groveling like a dog now. (rolls eyes)");
		
		next_dialogue(&head, 0);
		head->intimacy_gain = -20;
		prev_dialogue(&head);
		
		next_dialogue(&head, 1);
		head->intimacy_gain = 20;
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

    return dialogue_list;
}

//recursive iteration
int use_dialogue(Heroine* heroine, Dialogue* dialogue, char* header_str) {
    char input;
    int gain;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

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


