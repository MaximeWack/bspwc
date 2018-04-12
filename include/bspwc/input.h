#ifndef INPUT_H
#define INPUT_H

#include <wayland-server.h>
#include <wlr/types/wlr_box.h>
#include <wlr/types/wlr_cursor.h>
#include <wlr/types/wlr_input_device.h>
#include <wlr/types/wlr_seat.h>

#include "bspwc/server.h"

#define INPUT_DEFAULT_SEAT_NAME "DEFAULT_SEAT"

struct input
{
    struct server* server;

    struct wl_listener new_input;
    struct wl_list seats;
};

const char* device_type(enum wlr_input_device_type type);

void handle_new_input(struct wl_listener* listener, void* data);

struct input* create_input(struct server* server);
void destroy_input(struct input* input);

#endif // INPUT_H
