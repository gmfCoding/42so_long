#include <mlx.h>
#include <stdlib.h>

#include "map.h"
#include "state.h"
#include "theme.h"
#include "libft.h"

void	destroy_map(t_map **map)
{
	free((*map)->tiles);
	free(*map);
	*map = NULL; 
}

void	destroy_texture(t_gamestate *gs, t_texture tex)
{
	mlx_destroy_image(gs->mlx, tex.img);
}

static void	destroy_ttex(t_gamestate *gs, t_tiletex *ttex)
{
	if (ttex->subquad)
	{
		destroy_texture(gs, ttex->tr);
		destroy_texture(gs, ttex->tl);
		destroy_texture(gs, ttex->br);
		destroy_texture(gs, ttex->bl);
	}
	destroy_texture(gs, ttex->full);
	ft_memset(ttex, 0, sizeof(t_tiletex));
}

void	destroy_theme(t_gamestate *gs, t_themeinfo **theme)
{
	t_themeinfo	*th;
	int	i;

	th = *theme;
	i = 0;
	while (i < TTEX_COUNT)
	{
		destroy_ttex(gs, &th->tiletexs[i]);
		i++;
	}
	destroy_texture(gs, th->entire);
	free(th);
	*theme = NULL;
}

void destroy_state(t_gamestate *state)
{

	destroy_theme(state, &state->theme);
	mlx_destroy_window(state->mlx, state->win);
	state->mlx = NULL;
	state->win = NULL;
	destroy_map(&state->map);
	free(state);
}
