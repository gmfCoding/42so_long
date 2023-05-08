/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:40:20 by clovell           #+#    #+#             */
/*   Updated: 2023/05/08 23:20:47 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"
#include <stdlib.h>

static char	*tiles_get(int x, int y, char *tiles, t_map *map)
{
	return &tiles[y * map->size_x + x];
}

/*	basic recursive flood fill
	if we aren't out of bounds or a wall tile, then:
	turn into a wall tile, checking same tile twice, causing infinite recurse,
	check if we are at the end tile
	repeat on neighbours
 */
static int	find_end(int x, int y, char *tiles, t_map *map)
{
	if (!bounds(map, x, y) || *tiles_get(x, y, tiles, map))
		return (0);
	*tiles_get(x, y, tiles, map) = 1;
	if (x == map->exit.x && y == map->exit.y)
		return (1);
	if (find_end(x, y + 1, tiles, map))
		return (1);
	if (find_end(x + 1, y, tiles, map))
		return (1);
	if (find_end(x, y - 1, tiles, map))
		return (1);
	if (find_end(x - 1, y, tiles, map))
		return (1);
	return (0);	
}

int	map_completeable(t_map *map)
{
	int		y;
	int		x;
	char	*tiles;
	char	*tile;
	int		error;

	tiles = malloc (map->size_x * map->size_y * sizeof(char));
	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			tile = tiles_get(x, y, tiles, map);
			*tile = get_tile(x, y, map).id == TILE_WALL;
			x++;
		}
		y++;
	}
	
	error = find_end(map->start.x, map->start.y, tiles, map);
	free(tiles);
	return (error);
}
