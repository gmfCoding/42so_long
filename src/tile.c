/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:51:06 by clovell           #+#    #+#             */
/*   Updated: 2023/04/27 17:23:50 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "map.h"
#include "state.h"

t_tile	new_tile(int id)
{
	t_tile	tile;	

	tile.id = id;
	tile.collectable = 0;
	return (tile);
}

t_tile	new_c_tile(int floor, int collectable)
{
	t_tile	tile;

	tile = new_tile(floor);
	tile.collectable = collectable;
	return (tile);
}

static void	define_image(t_gamestate *state, int expected, int id, char *path)
{
	void	**images;
	void	*mlx;
	int		x;
	int		y;

	if (expected != id)
		return ;
	mlx = state->mlx;
	images = state->tile_images;
	images[id] = mlx_xpm_file_to_image(mlx, path, &x, &y);
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
