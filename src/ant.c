#include <pebble.h>
#include <antfarm.h>

#define RIGHT  0
#define UP     1
#define LEFT   2
#define DOWN   3
  
Ant* ant_spawn() {
  Ant *ant = malloc(sizeof(Ant));
  ant->direction = DOWN;
  ant->position = SPAWN_POINT;
  ant->hunger = 0;
  return ant;
}

void ant_despawn(Ant *ant) {
  free(ant);
}

void ant_move(Ant *ant) {
  // Change direction?
  switch(rand() % 14) {
    case 0:
      ant->direction = RIGHT;
      break;
    case 1:
      ant->direction = UP;
      break; 
    case 2:
      ant->direction = LEFT;
      break;
    case 3:
      ant->direction = DOWN;
      break;
    default:
      break; // Don't change direction most of time
  }
  
  // Update position
  if (ant->direction == RIGHT || ant->direction == LEFT) {
    if (ant->position.x < ANTFARM_DIMENSION_X) 
      ant->position.x += (ant->direction == RIGHT ? MOVE_DISTANCE : -MOVE_DISTANCE);
  } else {
    if (ant->position.y < ANTFARM_DIMENSION_Y) 
      ant->position.y += (ant->direction == DOWN ? MOVE_DISTANCE : -MOVE_DISTANCE);
  }
}

void ant_eat(Ant *ant) {
  // TODO: For when food is ready...
}

void ant_gather(Ant *ant) {
  // TODO: For when food is ready...
}

void ant_update(Ant *ant) {
  // Food before digging
  /* TODO: For when food is ready...
  if (food) {
    ant_gather(ant);
  } else {
    ant_move(ant);
  }
  */
  ant_move(ant);
  ant_eat(ant);
}



