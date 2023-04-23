#include "state.h"
#include <mlx_int.h>
#include "ft_printf.h"

void on_input(int key, t_gamestate *state)
{
	ft_printf("%d", key);
	return (1);
}