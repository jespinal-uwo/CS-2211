#include "worldcup_team.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Structure that represents a team, each structure will be a node in the linked list 
struct team_node
{
    int team_code;
    char team_name[TEAM_NAME_LENGTH + 1];
    char group_seeding[GROUP_SEEDING_LENGTH + 1];
    char uniform_colour[COLOURS_LENGTH + 1];

    struct team_node *next; // Pointer that points to the next node/structure in the linked list. 
};

// Pointer that points to the first structure/node in the linked list
struct team_node *first_team_node = NULL;

// Function prototypes
bool search_team_list_code(struct team_node **list, int n);
bool search_team_list_name(struct team_node **list, char *str);
bool search_team_list_seeding(struct team_node **list, char *str);
void add_to_team_list(struct team_node **list, int n, char *name_team, char *seeding_group, char colour_uniform);
void update_team_insert(int code_team);
int read_line(char str[], int n);

// Inserts a new team in the databse
void insert_team(void)
{
    
    int code_team, group_letter, seeding, colour_char;
    char name_team_string[TEAM_NAME_LENGTH + 1], group_seeding_string[GROUP_SEEDING_LENGTH + 1];

    printf("\tEnter team code: ");
    scanf("%d", &code_team);

    // Ensures that each team code is greater than or equal to 0
    if (code_team < 0)
    {
        printf("Teams codes must be an integer greater than or equal to 0 \n\n");
        return;
    }

    // Ensures that each team code is unique in the databse
    if (search_team_list_code(&first_team_node, code_team))
    {
        printf("Team already exists!\n\n");
        return;
    }

    // Prompts the user for the name of the team and stores it into a character array
    printf("\tEnter team name: ");
    read_line(name_team_string, TEAM_NAME_LENGTH);

    // Ensures that the name of the teams are unique in the databse 
    if (search_team_list_name(&first_team_node, name_team_string))
    {
        printf("Team name already exists!\n\n");
        return;
    }

    // Writes the group seeding into a character array
    printf("\tEnter group seeding: ");
    read_line(group_seeding_string, GROUP_SEEDING_LENGTH);

    // Splits the group letter and the seeding into 2 and stores them in
    // 2 int variables
    group_letter = (int)group_seeding_string[0];
    seeding = (int)group_seeding_string[1];

    // Checks the ASCII integer representation of their characters to check if the 
    // group letter falls between A-H and the seeding between 1-4
    if ((group_letter < 65 || group_letter > 72) || (seeding < 49 || seeding > 52))
    {
        printf("Only groups A-H and seeds 1-4 are acceptable!\n\n");
        return;
    }

    // Checks to see if the group seedings is unique in the database
    if (search_team_list_seeding(&first_team_node, group_seeding_string))
    {
        printf("Group seedding already exists!\n\n");
        return;
    }

    // Asks the user for the kit colour
    printf("\tEnter the kit colour: ");
    colour_char = getchar();

    // Removes whitespace
    while (getchar() != '\n')
        ;

    int flag = -1;

    char colour_list[] = "ROYGBIV";

    // Checks to see if the kit colour is one of "ROYGBIV"
    for (int i = 0; i < strlen(colour_list); i++)
    {
        if (colour_list[i] == colour_char)
            flag = 0;
    }

    // prints error message
    if (flag == -1)
    {
        printf("\n");
        printf("Only the values 'R', 'O', 'Y', 'G', 'B', 'I', 'V' are acceptable.\n\n");
        return;
    }

    // Stores all the information prompted to the user into the databse
    add_to_team_list(&first_team_node, code_team, name_team_string, group_seeding_string, colour_char);
}

// Function that searches the database for a specific team and prints out the information only for that team
void search_team(void)
{
    printf ("\n");
    int code_team;

    // asks the user for the team code
    printf("\tEnter team code: ");
    scanf("%d", &code_team);

    // Checks if the team code is first found in the databse, otherwise it tells the user
    // that the team code doesn't exist in the database
    if (search_team_list_code(&first_team_node, code_team))
    {


        // Prints the team's information of the team code specified by the user
        printf("\n");
        printf("%-15s%-25s%-20s%-30s\n", "Team Code", "Team Name", "Group Seeding", "Primary Kit Colour");

        struct team_node *p;

        // Searches through the linked list of team structures for the node with the team code 
        // specified by the user
        for (p = first_team_node; p != NULL; p = p->next)
        {
            if (p->team_code == code_team)
            {
                printf("%-15d%-25s%-20s%-30s\n", p->team_code, p->team_name, p->group_seeding, p->uniform_colour);
                break;
            }
        }
        printf("\n");
        return;
    }

    printf("Team code %d not found in the database.\n\n", code_team);
}

// Updates a team's information to the new information specified by the user
void update_team(void)
{
    printf ("\n");
    int code_team;

    // asks the user for the team code
    printf("\tEnter team code: ");
    scanf("%d", &code_team);

    // Checks if the team code is first found in the databse, otherwise it tells the user
    // that the team code doesn't exist in the database
    if (search_team_list_code(&first_team_node, code_team))
    {
        update_team_insert(code_team); // calls the function that updates the team's information
        return;
    }

    printf("Team code %d not found in the database.\n\n", code_team);
}
void print_team(void)
{

    // prints in a tabular form all teams along with their team code, team name, group seeding, and primary
    // kit colour
    printf("\n");
    printf("%-15s%-25s%-20s%-30s\n", "Team Code", "Team Name", "Group Seeding", "Primary Kit Colour");

    struct team_node *p;

     // Searches through the linked list of team structures to find all the nodes in the linked list
     // to print the information stores inside of them
    for (p = first_team_node; p != NULL; p = p->next)
    {
        printf("%-15d%-25s%-20s%-30s\n", p->team_code, p->team_name, p->group_seeding, p->uniform_colour);
    }

    printf("\n");
}

// Function that deletes a team from the database
void delete_team(void)
{
    printf ("\n");
    int code_team;

    // asks the user for the team code
    printf("\tEnter team code: ");
    scanf("%d", &code_team);

     // Checks if the team code is first found in the databse, otherwise it tells the user
    // that the team code doesn't exist in the database
    if (search_team_list_code(&first_team_node, code_team))
    {

        // Current pointer keeps track of the current node as the algorithms searches the linked list
        // while the previous pointer is the node the precedes the current node
        struct team_node *current, *previous;

        // Searches through the linked list for the team with the team node to be deleted
        for (current = first_team_node, previous = NULL; current->team_code != code_team; previous = current, current = current->next)
            ;
        
        if (previous == NULL) // Means that the team to be deleted was the first in the linked list
            first_team_node = first_team_node->next;
        else
            previous->next = current->next; // deletes the node 

        free(current); // frees the memory block of the deleted node

        printf("Team code %d was succesfully deleted from the databse\n\n", code_team);
        return;
    }

    printf("Team code %d not found in the database.\n\n", code_team);
}

// Function that returns true if the group seeding specified by the function's parameter
// exists in the linked list of team structure. Otherwise it returns false
bool search_team_list_seeding(struct team_node **list, char *str)
{

    struct team_node *p;

    for (p = *list; p != NULL; p = p->next)
    {
        if (strcmp(p->group_seeding, str) == 0)
            return true;
    }

    return false;
}

// Function that returns true if the team code specified by the function's parameter
// exists in the linked list of team structure. Otherwise it returns false
bool search_team_list_code(struct team_node **list, int n)
{

    struct team_node *p;

    for (p = *list; p != NULL; p = p->next)
    {
        if (p->team_code == n)
            return true;
    }

    return false;
}

// Function that returns true if the team name specified by the function's parameter
// exists in the linked list of team structure. Otherwise it returns false
bool search_team_list_name(struct team_node **list, char *str)
{

    struct team_node *p;

    for (p = *list; p != NULL; p = p->next)
    {
        if (strcmp(p->team_name, str) == 0)
            return true;
    }

    return false;
}

// Function that adds a team structure into the linked list of team structures
void add_to_team_list(struct team_node **list, int n, char *name_team, char *seeding_group, char colour_uniform)
{

    struct team_node *new_node; // new node to be inserted into the linked list

    new_node = malloc(sizeof(struct team_node)); // allocates memory for a team structure

    if (new_node == NULL) // Failed to allocate memory for the new team structure
    {
        printf("Error: Database is full!\n");
    }

    // Stores all the information into the team structure     
    new_node->team_code = n;
    strcpy(new_node->team_name, name_team);
    strcpy(new_node->group_seeding, seeding_group);

    switch (colour_uniform)
    {
    case 'R':
        strcpy(new_node->uniform_colour, "Red");
        break;
    case 'O':
        strcpy(new_node->uniform_colour, "Orange");
        break;
    case 'Y':
        strcpy(new_node->uniform_colour, "Yellow");
        break;
    case 'G':
        strcpy(new_node->uniform_colour, "Green");
        break;
    case 'B':
        strcpy(new_node->uniform_colour, "Blue");
        break;
    case 'I':
        strcpy(new_node->uniform_colour, "Indigo");
        break;
    case 'V':
        strcpy(new_node->uniform_colour, "Violet");
        break;
    }

    new_node->next = *list; // sets the next pointer of the team structure to the first node in the linked list
    *list = new_node; // makes the list point to the new node (making it the first node in the linked list)
}

// Function that updates a team whose team code is specified by the user
void update_team_insert(int code_team)
{
    
    int group_letter, seeding, colour_char;
    char name_team_string[TEAM_NAME_LENGTH + 1], group_seeding_string[GROUP_SEEDING_LENGTH + 1], colour;

    // Prompts the user for the new name of the team
    printf("\tEnter team name: ");
    read_line(name_team_string, TEAM_NAME_LENGTH);
 

    // Searches through the database to see if the new name of the team already exists
    for (struct team_node *p = first_team_node; p != NULL; p = p->next)
    {
        // Ensures that the new name can be the same as the name that already existed in the database
        // for that team code
        if ((strcmp(p->team_name, name_team_string) == 0 ) && (p->team_code != code_team))
        {
            printf("Team name already exists!\n\n");
            return;
        }
    }

    printf("\tEnter group seeding: ");
    read_line(group_seeding_string, GROUP_SEEDING_LENGTH);
    
     // Splits the group letter and the seeding into 2 and stores them in
    // 2 int variables 
    group_letter = (int)group_seeding_string[0];
    seeding = (int)group_seeding_string[1];

    // Checks the ASCII integer representation of their characters to check if the 
    // group letter falls between A-H and the seeding between 1-4
    if ((group_letter < 65 || group_letter > 72) || (seeding < 49 || seeding > 52))
    {
        printf("Only groups A-H and seeds 1-4 are acceptable!\n\n");
        return;
    }

    // Searches through the database to see if the group seeding of the team already exists
    for (struct team_node *p = first_team_node; p != NULL; p = p->next)
    {
        // Ensures that the new group seeding can be the same as the  
        // group seeding that already existed in the databse for that team code
        if ((strcmp(p->group_seeding, group_seeding_string) == 0 ) && (p->team_code != code_team))
        {
            printf("Group seeding already exists!\n\n");
            return;
        }
    }

    // Asks the user for the kit colour
    printf("\tEnter the kit colour: ");
    colour_char = getchar();

    // Removes whitespace
    while (getchar() != '\n')
        ;

    int flag = -1;

    char colour_list[] = "ROYGBIV";

    // Checks to see if the kit colour is one of "ROYGBIV"
    for (int i = 0; i < strlen(colour_list); i++)
    {
        if (colour_list[i] == colour_char)
            flag = 0;
    }

    // prints error message
    if (flag == -1)
    {
        printf("\n");
        printf("Only the values 'R', 'O', 'Y', 'G', 'B', 'I', 'V' are acceptable.\n\n");
        return;
    }

    
    // Updates the team with the specified team code with the new information 
    // provided by the user
    for ( struct team_node *p = first_team_node; p != NULL; p = p->next)
    {
        if (p->team_code == code_team)
        {

            strcpy(p->group_seeding, group_seeding_string);
            strcpy(p->team_name, name_team_string);

            switch (colour_char)
            {
            case 'R':
                strcpy(p->uniform_colour, "Red");
                break;
            case 'O':
                strcpy(p->uniform_colour, "Orange");
                break;
            case 'Y':
                strcpy(p->uniform_colour, "Yellow");
                break;
            case 'G':
                strcpy(p->uniform_colour, "Green");
                break;
            case 'B':
                strcpy(p->uniform_colour, "Blue");
                break;
            case 'I':
                strcpy(p->uniform_colour, "Indigo");
                break;
            case 'V':
                strcpy(p->uniform_colour, "Violet");
                break;
            }
        }
    }
}

// Function that reads in a string and stores it in the string argument
// when the fucntion is called
int read_line(char str[], int n)
{
    int ch, i = 0;

    // removes any leading whitspace
    while (isspace(ch = getchar()))
        ;
    while (ch != '\n' && ch != EOF)
    {
        if (i < n)
            str[i++] = ch; // stores character in the string
        ch = getchar();
    }

    // adds the null character to the of the string
    str[i] = '\0';
    return i; // returns the number of characters stored in the string
}