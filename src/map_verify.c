/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:48:58 by clovell           #+#    #+#             */
/*   Updated: 2023/05/11 14:46:34 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "map.h"

#define C_EXIT 0
#define C_POS 1

static void	count_prop(int tprop, int prop, int *dst)
{
	if (tprop == prop)
		(*dst)++;
}

t_error	verify_contains(t_map *map)
{
	int	y;
	int	x;
	int	counted[2];
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
			count_prop(properror, TPROP_COLLECT, &map->collectables);
			count_prop(properror, TPROP_EXIT, &counted[C_EXIT]);
			x++;
		}
		y++;
	}
	properror = E_NONE;
	properror |= (counted[C_EXIT] != 1) * E_EXIT;
	properror |= (counted[C_POS] != 1) * E_POS;
	properror |= (map->collectables <= 0) * E_COLL;
	return (properror);
}

t_error	verify_boundary(t_map *map)
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
					return (E_BOUND);
			x++;
		}
		y++;
	}
	return (E_NONE);
}

int	bounds(t_map *map, int x, int y)
{
	int	boundx;
	int	boundy;

	boundx = (x >= 0 && x < map->size_x);
	boundy = (y >= 0 && y < map->size_y);
	return (boundx && boundy);
}
