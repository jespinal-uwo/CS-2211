#ifndef WORLD_CUP_TEAM
#define WORLD_CUP_TEAM

// Macro definitions for the maxiumum lengths of strings a team structure's attributes can have.
#define TEAM_NAME_LENGTH 24
#define GROUP_SEEDING_LENGTH 2
#define COLOURS_LENGTH 30

// Function prototypes that define the function used to manage teams
void insert_team (void);
void search_team (void);
void update_team (void);
void print_team (void);
void delete_team (void);




#endif 