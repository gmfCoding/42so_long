/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:48:58 by clovell           #+#    #+#             */
/*   Updated: 2023/05/08 23:06:14 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "map.h"

#define C_EXIT 0
#define C_COLL 1
#define C_POS 2

#define ERR_NONE 0
#define ERR_EXIT 1
#define ERR_COLL 2
#define ERR_POS 4
#define ERR_BOUND 8

static void	count_prop(int tprop, int prop, int *dst)
{
	if (tprop == prop)
		(*dst)++;
}

int	verify_contains(t_map *map)
{
	int	y;
	int	x;
	int	counted[3];
	int	properror;

	ft_memset(counted, 0, sizeof(int) * 3);
	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			properror = get_tile(x, y, map).property;
			count_prop(properror, TPROP_POS, &counted[C_POS]);
			count_prop(properror, TPROP_COLLECT, &counted[C_COLL]);
			count_prop(properror, TPROP_EXIT, &counted[C_EXIT]);
			x++;
		}
		y++;
	}
	properror = ERR_NONE;
	properror |= (counted[C_EXIT] != 1) * ERR_EXIT;
	properror |= (counted[C_POS] != 1) * ERR_POS;
	properror |= (counted[C_COLL] <= 0) * ERR_COLL;
	return (properror);
}

int	verify_boundary(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while ((y == 0 || y == map->size_y - 1) && x < map->size_x)
		{
			if ((x == 0 || x == map->size_x - 1))
				if (get_tile(x, y, map).id != TILE_WALL)
					return (ERR_BOUND);
			x++;
		}
		y++;
	}
	return (ERR_NONE);
}

int	bounds(t_map *map, int x, int y)
{
	int	boundx;
	int	boundy;

	boundx = (x >= 0 && x < map->size_x);
	boundy = (y >= 0 && y < map->size_y);
	return (boundx && boundy);
}
