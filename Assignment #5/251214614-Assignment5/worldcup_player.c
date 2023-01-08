#include "worldcup_player.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Structure that represents a player, each structure will be a node in the linked list 
struct player_node
{
    int player_code;
    char player_name[PLAYER_NAME_LENGTH + 1];
    int player_age;
    char player_club_affiliation[PLAYER_CLUB_AFFILIATION_LENGTH + 1];

    struct player_node *next; // Pointer that points to the next node/structure in the linked list 
};

// Pointer that points to the first structure/node in the linked list
struct player_node *first_player_node = NULL;

// Function prototypes
bool search_player_list_code(struct player_node **list, int n);
int read_line(char str[], int n);
void add_to_player_list(struct player_node **list, int code_player, char *player_name_string, int age_player,
                        char *player_club_affiliation_string);
int read_line(char str[], int n);

// Inserts a new player in the databse

void insert_player(void)
{

    int code_player, age_player;
    char player_name_string[PLAYER_NAME_LENGTH + 1], player_club_affiliation_string[PLAYER_CLUB_AFFILIATION_LENGTH + 1];

    printf("\tEnter player's code: ");
    scanf("%d", &code_player);

     // Ensures that each player code is greater than or equal to 0
    if (code_player < 0)
    {
        printf("Player codes must be an integer greater than or equal to 0 \n\n");
        return;
    }

    // Ensures that each player code is unique in the databse
    if (search_player_list_code(&first_player_node, code_player))
    {
        printf("Player code already exists!\n\n");
        return;
    }

    // Prompts the user for the name of the player and stores it into a character array
    printf("\tEnter the player's name: ");
    read_line(player_name_string, PLAYER_NAME_LENGTH);

    printf("\tEnter the player's age: ");
    scanf("%d", &age_player);

    // Ensures that the age of the player is between 17 and 99 inclusive
    if (age_player < 17 || age_player > 99)
    {
        printf("The player's age must be 17-99!\n\n");
        return;
    }

    // Prompts the user for the professional club affiliation 
    // of the player and stores it into a character array
    printf("\tEnter the player's professional club affiliation: ");
    read_line(player_club_affiliation_string, PLAYER_CLUB_AFFILIATION_LENGTH);

    // Stores all the information prompted to the user into the databse
    add_to_player_list(&first_player_node, code_player, player_name_string, age_player,
                       player_club_affiliation_string);
}

// Function that searches the database for a specific player and prints out the information only for that player
void search_player(void)
{

    int code_player;

    // asks the user for the player code
    printf("\tEnter the player's code: ");
    scanf("%d", &code_player);

     // Checks if the player code is first found in the databse, otherwise it tells the user
    // that the player code doesn't exist in the database
    if (search_player_list_code(&first_player_node, code_player))
    {

         // Prints the players's information of the player code specified by the user
        printf ("\n");
        printf("%-15s%-25s%-20s%-30s\n", "Player Code", "Player Name", "Age", "Club");

        struct player_node *p;

         // Searches through the linked list of player structures for the node with the player code 
        // specified by the user
        for (p = first_player_node; p != NULL; p = p->next)
        {
            if (p->player_code == code_player)
            {
                printf("%-15d%-25s%-20d%-30s\n", p->player_code, p->player_name, p->player_age, p->player_club_affiliation);
                break;
            }
        }
        printf("\n");
        return;
    }

    printf("Player code %d not found in the database.\n\n", code_player);
}

// Updates a players's information to the new information specified by the user
void update_player(void)
{
    int code_player;

    // asks the user for the player code
    printf("\tEnter the player's code: ");
    scanf("%d", &code_player);

    // Checks if the player code is first found in the databse, otherwise it tells the user
    // that the player code doesn't exist in the database
    if (search_player_list_code(&first_player_node, code_player))
    {

        int age_player;
        char player_name_string[PLAYER_NAME_LENGTH + 1], player_club_affiliation_string[PLAYER_CLUB_AFFILIATION_LENGTH + 1];

        // Prompts the user for the new name of the player
        printf("\tEnter the player's name: ");
        read_line(player_name_string, PLAYER_NAME_LENGTH);

        // Prompts the user for the new age of the player
        printf("\tEnter the age of the player: ");
        scanf("%d", &age_player);

        // Ensures that the new age of the player is between 17 and 99 inclusive
        if (age_player < 17 || age_player > 99)
        {
            printf("The age of the player must be 17-99!\n\n");
            return;
        }

        // Prompts the user for the new professional club affiliation
        // of the player
        printf("\tEnter the player's professional club affiliation: ");
        read_line(player_club_affiliation_string, PLAYER_CLUB_AFFILIATION_LENGTH);

        // Updates the player with the specified team code with the new information 
        // provided by the user
        struct player_node *p;

        // Searches through the linked list of player structure to find the node with the
        // player code specified by the user to updates its information that is also
        // specified by the user
        for (p = first_player_node; p!=NULL; p = p->next){

            if (p->player_code == code_player){
                p->player_age = age_player;
                strcpy(p->player_name, player_name_string);
                strcpy (p->player_club_affiliation, player_club_affiliation_string);
            }

        }

        printf("Player code %d was succesfully updated \n\n", code_player);
        return; 
    }

    printf("Player code %d not found in the database.\n\n", code_player);
}
void print_player(void)
{

    // prints in a tabular form all players along with their player code, player name, age, and professional
    // club affiliation
    printf("\n");
    printf("%-15s%-25s%-20s%-30s\n", "Player Code", "Player Name", "Age", "Club");

    struct player_node *p;

    // Searches through the linked list of player structures to find all the nodes in the linked list
     // to print the information stores inside of them
    for (p = first_player_node; p != NULL; p = p->next)
    {
        printf("%-15d%-25s%-20d%-30s\n", p->player_code, p->player_name, p->player_age, p->player_club_affiliation);
    }

    printf("\n");
}

// Function that deletes a player from the database
void delete_player(void)
{

    int code_player;

    // asks the user for the player code
    printf("\tEnter the player's code: ");
    scanf("%d", &code_player);

    // Checks if the player code is first found in the databse, otherwise it tells the user
    // that the team code doesn't exist in the database
    if (search_player_list_code(&first_player_node, code_player))
    {

        // Current pointer keeps track of the current node as the algorithms searches the linked list
        // while the previous pointer is the node the precedes the current node
        struct player_node *current, *previous;

        // Searches through the linked list for the player with the player node to be deleted
        for (current = first_player_node, previous = NULL; current->player_code != code_player; previous = current, current = current->next)
            ;

        if (previous == NULL)   // Means that the player to be deleted was the first in the linked list
            first_player_node = first_player_node->next;
        else
            previous->next = current->next; // deletes the player 

        free(current); // frees the memory block of the deleted player

        printf("Player code %d was succesfully deleted from the database\n\n", code_player);
        return;
    }

    printf("Player code %d not found in the database.\n\n", code_player);
}

// Function that adds a player structure into the linked list of player structures
void add_to_player_list(struct player_node **list, int code_player, char *player_name_string, int age_player,
                        char *player_club_affiliation_string)
{

    struct player_node *new_node; // new node to be inserted into the linked list

    new_node = malloc(sizeof(struct player_node)); // allocates memory for a player structure

    if (new_node == NULL) // Failed to allocate memory for the new player structure
    {
        printf("Error: Database is full!\n");
    }

    // Stores all the information into the player structure     
    new_node->player_code = code_player;
    strcpy(new_node->player_name, player_name_string);
    new_node->player_age = age_player;
    strcpy(new_node->player_club_affiliation, player_club_affiliation_string);

    new_node->next = *list; // sets the next pointer of the player structure to the first node in the linked list
    *list = new_node; // makes the list point to the new node (making it the first node in the linked list)
}

// Function that returns true if the player code specified by the function's parameter
// exists in the linked list of player structure. Otherwise it returns false
bool search_player_list_code(struct player_node **list, int n)
{

    struct player_node *p;

    for (p = *list; p != NULL; p = p->next)
    {
        if (p->player_code == n)
            return true;
    }

    return false;
}
