/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:53:37 by clovell           #+#    #+#             */
/*   Updated: 2023/04/24 17:37:44 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>

#include "movement.h"
#include "vector.h"
#include "state.h"
#include "texture.h"
#include "libft.h"
#include "ft_printf.h"


static void push_sprite(t_gamestate *gs, t_sprite *sprite)
{
	t_vec		pos;
	t_texture	tex;
	void		*mlx;
	void		*win;

	pos = sprite->pos;
	tex = sprite->tex;
	mlx = gs->mlx;
	win = gs->win;
	mlx_put_image_to_window(mlx, win, tex.img, pos.x, pos.y);
}

static void define_image(t_gamestate *state, int expected, int id, char *path)
{
	void	**images;
	void	*mlx;
	int x;
	int y;
	
	if (expected != id)
		return ;

	mlx = state->mlx;
	images = state->images;
	(*images)[id] = mlx_xpm_file_to_img(mlx, path, &x, &y);
}

void	*get_tile_image(t_gamestate *state, int id)
{
	if (!state->tile_images[id])
	{
		define_image(state, TILE_FLOOR, id, "assets/tile_dirt.xpm");
		define_image(state, TILE_WALL, id, "assets/tile_wall.xpm");
	}	
	return (state->tile_images[id]);
}

int	on_frame(void *param)
{
	t_gamestate *gs;
	t_list	*sp_next;
	int x;
	int y;

	gs = (t_gamestate*)param;
	mlx_clear_window(gs->mlx, gs->win);
	sp_next = gs->sprites;
	while (sp_next && sp_next->next)
	{
		push_sprite(gs, sp_next->content);
		sp_next = sp_next->next;
	}
	y = 0;
	while (y < gs->map->size_y)
	{
		x = 0;
		while (x < gs->map->size_x)
		{
			mlx_put_image_to_window(gs->mlx, gs->win, get_tile_image(gs, gs->map->tiles[y * gs->map->size_x + x].id) , 96 * x, 96 * y);	
			x++;
		}
		y++;
	}
	mv_process_movement(gs->player, &gs->move);
	push_sprite(gs, gs->player);
	return (0);
}
