#include "state.h"
#include <mlx_int.h>
#include <stdio.h>

void on_input(int key, t_gamestate *state)
{
	char str[12];
	int size = sprintf(str, "%d", key);

	write(state->logfile, "hello", 6);
}