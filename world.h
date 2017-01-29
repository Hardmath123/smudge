#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define WORLD_TIMEOUT 4
#define WORLD_CAPACITY 1024


typedef struct world {
    struct player* players[1024];
} world_t;

void  world_init();
void* world_loop(void* world_void);

typedef struct player {
    int x;
    int y;
    world_t* world;
    pthread_t server;
    long int ping;
} player_t;

player_t* player_init(pthread_t server);
void player_tick(player_t* p);
void player_char(player_t* p, char c);
void player_draw(player_t* p, char* buf, int width, int height);
