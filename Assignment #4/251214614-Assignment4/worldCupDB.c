/* Name: worldCupDB.c
   Purpose: Simple C program that implements a database of teams (nations)
            using a structure
    Author: Juan Espinal
    Student #: 251214614
                        */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TEAM_NAME_LENGTH 24
#define GROUP_SEEDING_LENGTH 2
#define TEAMS_LENGTH 32
#define COLOURS_LENGTH 100

// structure that represents a team with several attributes
struct team
{
    int team_code;
    char team_name[TEAM_NAME_LENGTH + 1];
    char group_seeding[GROUP_SEEDING_LENGTH + 1];
    char uniform_colours[COLOURS_LENGTH + 1];
} teams[TEAMS_LENGTH]; // an array of structures which represent the database

// Global Variable that keeps track of the number of teams,
// only 32 team structures are allowed in the database
int num_of_teams = 0;

// Function Prototypes
int read_line(char str[], int n);

void insert(void);

void updateInsert(int code_team);

void search(void);

void update(void);

void print_team(void);

int main(void)
{

    printf("\n");
    printf("******************\n");
    printf("* 2211 World Cup *\n");
    printf("******************\n\n");

    // Initializes all team structures in the array to have a team code of -1
    // since normally arrays in C are automatically initialized to 0 
    for (int i = 0; i < TEAMS_LENGTH; i++)
    {
        teams[i].team_code = -1;
    }

    char code;
    for (;;)
    {
        // Prompts the user for the operation code
        printf("Enter operation code : ");
        scanf(" %c", &code);

        // removes whitespace 
        while (getchar() != '\n')
            ;

        // Performs various functions depending on user input,
        // if user presses 'q' they quit the program
        switch (code)
        {
        case 'i':
            insert();
            break;
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'p':
            print_team();
            break;
        case 'q':
            return 0;
        default:
            printf("Invalid Command. Try again!\n\n");
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

void insert(void)
{

    // Ensures that only 32 teams are stored in the database
    if (num_of_teams > 32)
    {
        printf("Database is full.\n\n");
        return;
    }

    int code_team, group_letter, seeding;
    char name_team_string[TEAM_NAME_LENGTH + 1], group_seeding_string[GROUP_SEEDING_LENGTH + 1], colour_char;

    printf("\tEnter team code: ");
    scanf("%d", &code_team);

    // Checks that the team code is between 0 and 31 inclusive 
    if (code_team < 0 || code_team > 31)
    {
        printf("Error! Only team codes 0-31 are acceptable\n\n");
        return;
    }


    // Checks that the team code is unique in the database
    for (int i = 0; i < TEAMS_LENGTH; i++)
    {
        if (teams[i].team_code == code_team)
        {
            printf("Team already exists\n\n");
            return;
        }
    }

    printf("\tEnter team name: ");

    // writes the string into the variable
    read_line(name_team_string, TEAM_NAME_LENGTH);

    // Checks that the teams name is unique in the database
    for (int i = 0; i < TEAMS_LENGTH; i++)
    {
        if (strcmp(teams[i].team_name, name_team_string) == 0)
        {
            printf("Team names must be unique\n\n");
            return;
        }
    }

    printf("\tEnter group seeding: ");

    // writes the string into the variable
    read_line(group_seeding_string, GROUP_SEEDING_LENGTH);

    // Splits the group letter and the seeding into 2 and stores them in
    // 2 int variables 
    group_letter = (int)group_seeding_string[0];
    seeding = (int)group_seeding_string[1];


    // Checks the ASCII integer representation of their characters to check if the 
    // group letter falls between A-H and the seeding between 1-4
    if ((group_letter < 65 || group_letter > 72) || (seeding < 49 || seeding > 52))
    {
        printf("Only groups A-H and seeds 1-4 are acceptable.\n\n");
        return;
    }

    // Checks to see if the group seedings is unique in the database
    for (int i = 0; i < TEAMS_LENGTH; i++)
    {
        if (strcmp(teams[i].group_seeding, group_seeding_string) == 0)
        {
            printf("Group Seedings must be unique\n\n");
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

    // stores all the information into the database (array of team structures)
    teams[code_team].team_code = code_team;
    strcpy(teams[code_team].team_name, name_team_string);
    strcpy(teams[code_team].group_seeding, group_seeding_string);

    switch (colour_char)
    {
    case 'R':
        strcpy(teams[code_team].uniform_colours, "Red");
        break;
    case 'O':
        strcpy(teams[code_team].uniform_colours, "Orange");
        break;
    case 'Y':
        strcpy(teams[code_team].uniform_colours, "Yellow");
        break;
    case 'G':
        strcpy(teams[code_team].uniform_colours, "Green");
        break;
    case 'B':
        strcpy(teams[code_team].uniform_colours, "Blue");
        break;
    case 'I':
        strcpy(teams[code_team].uniform_colours, "Indigo");
        break;
    case 'V':
        strcpy(teams[code_team].uniform_colours, "Violet");
        break;
    }

    // adds 1 to the number of teams in the database
    num_of_teams++;

    printf("\n\n");
}

void search(void)
{

    
    int code_team;

    // asks the user for the team code
    printf("\tEnter team code: ");
    scanf("%d", &code_team);

    printf("\n");

    // prints the team with the team code specified by the user
    for (int i = 0; i < TEAMS_LENGTH; i++)
    {
        if (teams[i].team_code == code_team)
        {
            printf("%-15s%-25s%-20s%-30s\n", "Team Code", "Team Name", "Group Seeding", "Primary Kit Colour");
            printf("%-15d%-25s%-20s%-30s\n", teams[i].team_code, teams[i].team_name,
                   teams[i].group_seeding, teams[i].uniform_colours);
            printf("\n\n");
            return;
        }
    }

    printf("Team code is not found in the database.\n\n");
}

void update(void)
{

    int code_team;

    // asks the user for the team code
    printf("\tEnter team code: ");
    scanf("%d", &code_team);

    for (int i = 0; i < TEAMS_LENGTH; i++)
    {
        if (teams[i].team_code == code_team)
        {
            updateInsert(code_team); // function that updates the team with specified team code
            return;
        }
    }

    printf("Team code is not found in the database.\n\n");
}

void print_team(void)
{

    // prints in a tabular form all teams along with their team code, team name, group seeding, and primary
    // kit colour
    printf("\n");
    printf("%-15s%-25s%-20s%-30s\n", "Team Code", "Team Name", "Group Seeding", "Primary Kit Colour");
    for (int i = 0; i < TEAM_NAME_LENGTH; i++)
    {

        if (teams[i].team_code != -1)
        {
            printf("%-15d%-25s%-20s%-30s\n", teams[i].team_code, teams[i].team_name,
                   teams[i].group_seeding, teams[i].uniform_colours);
        }
    }

    printf("\n");
}

void updateInsert(int code_team)
{

    int group_letter, seeding;
    char name_team_string[TEAM_NAME_LENGTH + 1], group_seeding_string[GROUP_SEEDING_LENGTH + 1], colour;

    printf("\tEnter team name: ");

    read_line(name_team_string, TEAM_NAME_LENGTH);

    // Checks to see if the team name is unique in the databse
    for (int i = 0; i < TEAMS_LENGTH; i++)
    {
        if (strcmp(teams[i].team_name, name_team_string) == 0 && strcmp(teams[i].team_name, teams[code_team].team_name) != 0)
        {
            printf("Team names must be unique\n\n");
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
        printf("Only groups A-H and seeds 1-4 are acceptable.\n\n");
        return;
    }

      // Checks to see if the group seedings is unique in the database

    for (int i = 0; i < TEAMS_LENGTH; i++)
    {
        if (strcmp(teams[i].group_seeding, group_seeding_string) == 0 && strcmp(teams[i].group_seeding, teams[code_team].group_seeding) != 0)
        {
            printf("Group Seedings must be unique\n\n");
            return;
        }
    }

    printf("\tEnter the kit colour: ");
    colour = getchar();

    while (getchar() != '\n') // removes white space
        ;

    int flag = -1;

    char colour_list[] = "ROYGBIV";

    // checks to see if kit colour is one of "ROYGBIV"
    for (int i = 0; i < strlen(colour_list); i++)
    {
        if (colour_list[i] == colour)
            flag = 0;
    }

    // prints error message
    if (flag == -1)
    {
        printf("\n");
        printf("Only the values 'R', 'O', 'Y', 'G', 'B', 'I', 'V' are acceptable.\n");
        return;
    }

    // stores all the team information into the database. (Array of structures)

    teams[code_team].team_code = code_team;
    strcpy(teams[code_team].team_name, name_team_string);
    strcpy(teams[code_team].group_seeding, group_seeding_string);

    switch (colour)
    {
    case 'R':
        strcpy(teams[code_team].uniform_colours, "Red");
        break;
    case 'O':
        strcpy(teams[code_team].uniform_colours, "Orange");
        break;
    case 'Y':
        strcpy(teams[code_team].uniform_colours, "Yellow");
        break;
    case 'G':
        strcpy(teams[code_team].uniform_colours, "Green");
        break;
    case 'B':
        strcpy(teams[code_team].uniform_colours, "Blue");
        break;
    case 'I':
        strcpy(teams[code_team].uniform_colours, "Indigo");
        break;
    case 'V':
        strcpy(teams[code_team].uniform_colours, "Violet");
        break;
    }

    printf("\n");
}