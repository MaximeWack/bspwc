#ifndef XDG_SHELL_V6_H
#define XDG_SHELL_V6_H

#include <assert.h>
#include <wayland-server.h>
#include <wlr/types/wlr_xdg_shell_v6.h>
#include <wlr/util/log.h>

#include "bspwc/server.h"
#include "bspwc/window.h"

struct xdg_surface_v6
{
	struct window* window;

	struct wl_listener surface_commit;

	struct wl_listener destroy;
	struct wl_listener new_popup;
	struct wl_listener map;
	struct wl_listener unmap;
	struct wl_listener request_move;
	struct wl_listener request_resize;
	struct wl_listener request_maximize;
	struct wl_listener request_fullscreen;

	uint32_t pending_move_resize_configure_serial;
};

void handle_surface_commit(struct wl_listener* listener, void* data);
void handle_destroy(struct wl_listener* listener, void* data);
void handle_new_popup(struct wl_listener* listener, void* data);
void handle_map(struct wl_listener* listener, void* data);
void handle_unmap(struct wl_listener* listener, void* data);
void handle_request_move(struct wl_listener* listener, void* data);
void handle_request_resize(struct wl_listener* listener, void* data);
void handle_request_maximize(struct wl_listener* listener, void* data);
void handle_request_fullscreen(struct wl_listener* listener, void* data);

void handle_xdg_shell_v6_surface(struct wl_listener* listener, void* data);

#endif // XDG_SHELL_V6_H
