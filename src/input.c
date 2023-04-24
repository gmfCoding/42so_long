#include "state.h"
#include "ft_printf.h"
#define KEYMAP_OSX
#include "input.h"

int on_input(int key, t_gamestate *state)
{
	if (key == KEY_W)
		state->player->pos.y += 10;
	ft_printf("%d\n", key);
	return (0);
}
