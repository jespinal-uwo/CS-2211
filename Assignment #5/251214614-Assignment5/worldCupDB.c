/* Name: worldCupDB
   Purpose: Simple C program that implements a database of teams (nations)
            and players using a linked list of structures
    Author: Juan Espinal
    Student #: 251214614
                        */

#include "worldCupDB.h"
#include <stdio.h>
#include <stdlib.h>

// Main function that prompts the user if they want to control the teams, players, or quit the program

int main (void){


    printf ("\n");
    printf ("******************\n");
    printf ("* 2211 World Cup *\n");
    printf ("******************\n\n");
    
    char code;
    for (;;){
        
        //Prompts the user for a set of commands
        printf ("Enter Command (h,q,t,p): ");
        scanf (" %c", &code);

        // Calls certain functions depending on the user's input
        switch (code){
            case 'h':
                help(); 
                break;          
            case 't':
                control_team();
                break;
            case 'p':
                control_player();
                break;
            case 'q':
                return 0;
            default:
                printf ("Invalid Command. Try again!\n\n");
        }

    }


  
}

// Asks the user for which commands to manipulate the teams in the database
void control_team (void){
    
    printf ("\n");

    char code;

    // Prompts the user for a set of commands
    printf ("Enter Operation code (i,s,u,p,d): ");
    scanf (" %c", &code);

    // Calls functions that are used to manage the teams depending on the user input
    switch (code){
        case 'i':
            insert_team();
            break;
        case 's':
            search_team();
            break;
        case 'u':
            update_team();
            break;
        case 'p':
            print_team();
            break;
        case 'd':
            delete_team();
            break;
        default:
            printf ("Invalid Command. Try again!\n\n");
    }
    

}

// Asks the user for which commands to manipulate the players in the database
void control_player (void){

    printf ("\n");

    char code;

    //Prompts the user for a set of commands
    printf ("Enter Operation code (i,s,u,p,d): ");
    scanf (" %c", &code);

    // Calls functions that are used to manage the players depending on the user input
    switch (code){
        case 'i':
            insert_player();
            break;
        case 's':
            search_player();
            break;
        case 'u':
            update_player();
            break;
        case 'p':
            print_player();
            break;
        case 'd':
            delete_player();
            break;
        default:
            printf ("Invalid Command. Try again!\n\n");
    }

}

//Function that provides a description of all the commands available to the user
void help (void){
    printf ("Commands:\n\n");
    printf ("q: Quits the program\n");
    printf ("t: Control the teams\n");
    printf ("\ti: Insert a new team\n");
    printf ("\ts: Search for a team in the database and prints it out\n");
    printf ("\tu: Update a team in the database\n");
    printf ("\tp: Print the entire list of team\n");
    printf ("\td: Delete a team\n");
    printf ("p: Control the players\n");
    printf ("\ti: Insert a new player\n");
    printf ("\ts: Search for a player in the database and prints it out\n");
    printf ("\tu: Update a player in the database\n");
    printf ("\tp: Print the entire list of players\n");
    printf ("\td: Delete a player\n\n");
}