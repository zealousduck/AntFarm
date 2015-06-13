#define ANT_H

typedef struct cartesian_location {
  int x, y;
} Location;

typedef struct ant_unit {
  int direction;
  Location position;
  int hunger;   // TODO: For when food is ready...
} Ant;

Ant* ant_spawn();
void ant_despawn(Ant*);
void ant_move(Ant*);
void ant_eat(Ant*);
void ant_gather(Ant*);
void ant_update(Ant*);