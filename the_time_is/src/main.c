#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"


#define MY_UUID { 0xAC, 0x46, 0xF1, 0x8D, 0xE9, 0xF4, 0x4C, 0x0E, 0xAA, 0x51, 0x2E, 0x1A, 0x15, 0xF0, 0x06, 0x27 }
PBL_APP_INFO(MY_UUID,
             "Now", "ZZZ",
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_WATCH_FACE);

Window window;
TextLayer text_layer;

void handle_init(AppContextRef ctx) {
    (void)ctx;
    
    window_init(&window, "Now");
    window_stack_push(&window, true /* Animated */);
    window_set_background_color(&window, GColorBlack);
    
    resource_init_current_app(&APP_RESOURCES);
 	
	text_layer_init(&text_layer, window.layer.frame);
    text_layer_set_text_color(&text_layer, GColorWhite);
    text_layer_set_background_color(&text_layer, GColorClear);
    text_layer_set_font(&text_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_ROBOTO_Bold_SUBSET_45)));
	//text_layer_set_font(&text_layer, fonts_get_system_font(FONT_KEY_GOTHAM_42_BOLD));
	layer_set_frame(&text_layer.layer, GRect (28, 50, 144-28, 168-50));
	text_layer_set_text(&text_layer, "Now");	
    layer_add_child(&window.layer, &text_layer.layer);

}
void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
}
