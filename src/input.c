#include "state.h"
#include "ft_printf.h"
#define KEYMAP_OSX
#include "input.h"
#include "movement.h"

int on_input_press(int key, t_gamestate *state)
{
	ft_printf("press:%d\n", key);
	mv_process_input(key, 1, &state->move);
	return (0);
}


int on_input_release(int key, t_gamestate *state)
{
	ft_printf("release:%d\n", key);
	mv_process_input(key, 0, &state->move);
	return (0);
}