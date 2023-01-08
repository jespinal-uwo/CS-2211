#ifndef WORLD_CUP_PLAYER
#define WORLD_CUP_PLAYER

// Macro definitions for the maxiumum lengths of strings player structure's attributes can have.
#define PLAYER_NAME_LENGTH 49
#define PLAYER_CLUB_AFFILIATION_LENGTH 49

// Function prototypes that define the function used to manage players
void insert_player (void);
void search_player (void);
void update_player (void);
void print_player (void);
void delete_player (void);


#endif