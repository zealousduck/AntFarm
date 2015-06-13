#include <pebble.h>
#include <antfarm.h>
  
void antfarm_new_ant(AntFarm *antfarm) {
  if (antfarm->num_ants < MAX_NUMBER_ANTS) {
    antfarm->ant_list[antfarm->num_ants] = *ant_spawn();
    antfarm->num_ants++;
  }
}

AntFarm* antfarm_create() {
  AntFarm *antfarm = malloc(sizeof(AntFarm));
  antfarm->num_ants = 0;
  for (int i = 0; i < STARTING_ANTS; i++) {
    antfarm_new_ant(antfarm);
  }
  return antfarm;
}  

void antfarm_destroy(AntFarm *antfarm) {
  free(antfarm);
}

void antfarm_update(AntFarm *antfarm) {
  // Update each of the ants
  for (int i = 0; i < antfarm->num_ants; i++) {
    ant_update(&antfarm->ant_list[i]);
  }
}
