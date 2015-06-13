#define ANTFARM_H
#include <ant.h>

#define ANTFARM_DIMENSION_X 144
#define ANTFARM_DIMENSION_Y 168
#define ANTFARM_DIMENSIONS (GRect(0,0,ANTFARM_DIMENSION_X,ANTFARM_DIMENSION_Y))    // Dimensions of the farm, screen size?
#define STARTING_ANTS       1
#define MAX_NUMBER_ANTS     10
#define UPDATE_INTERVAL     2  // Subject to change, corresponds to seconds?

typedef struct antfarm_struct {
  Ant ant_list[MAX_NUMBER_ANTS];
  int num_ants;
} AntFarm; 

void antfarm_new_ant(AntFarm*);
AntFarm* antfarm_create();
void antfarm_destroy(AntFarm*);
void antfarm_update(AntFarm*);
