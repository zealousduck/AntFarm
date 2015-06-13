#include <pebble.h>
#include <antfarm.h>

static Window *s_main_window;  

static Layer *s_ant_layer;
static Layer *s_tunnel_layer;
static BitmapLayer *s_background_layer;

static AntFarm *antfarm;

static void ant_layer_draw(Layer *layer, GContext *ctx) {
  // Setup
  GRect bounds = layer_get_bounds(layer);
  graphics_context_set_fill_color(ctx, GColorBlack);
  
  // Draw ants
  Ant current; GPoint point;
  for (int i = 0; i < antfarm->num_ants; i++) {
    current = antfarm->ant_list[i];
    point = GPoint(current.position.x, current.position.y);
    graphics_draw_pixel(ctx, point);
  }
}



static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  //ant_farm_update();
}

static void main_window_load(Window *window) {
  // Background Load
  
  // Tunnel Load
  
  // Ant Load
  s_ant_layer = layer_create(ANTFARM_DIMENSIONS);
}  
  
static void main_window_unload(Window *window) {
  // Background Unload
  
  // Tunnel Unload
  
  // Ant Unload
  layer_destroy(s_ant_layer);
}
  
static void init() {
  // Create main window element and assign to pointer
  s_main_window = window_create();
  
  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  
  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);
  
  // Register with TickTimerService
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  
  // Create antfarm
  antfarm = antfarm_create();
}

static void deinit() {
  // Destroy window
  window_destroy(s_main_window);
  
  // Unregister with TickTimerService (don't need when app not visible)
  tick_timer_service_unsubscribe();
  
  // Save antfarm to persistent data
  
  // Destroy antfarm
  antfarm_destroy(antfarm);
}
  
int main(void) {
  srand(0);
  init();
  app_event_loop();
  deinit();
}
  