/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:51:06 by clovell           #+#    #+#             */
/*   Updated: 2023/05/11 14:21:09 by clovell          ###   ########.fr       */
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
	tile.property = TPROP_NONE;
	return (tile);
}

t_tile	new_c_tile(int floor, int collectable)
{
	t_tile	tile;

	tile = new_tile(floor);
	tile.property = TPROP_COLLECT;
	tile.collectable = collectable;
	return (tile);
}

t_tile	new_e_tile(int floor)
{
	t_tile	tile;

	tile = new_tile(floor);
	tile.property = TPROP_EXIT;
	return (tile);
}

t_tile	new_s_tile(int floor)
{
	t_tile	tile;

	tile = new_tile(floor);
	tile.property = TPROP_POS;
	return (tile);
}
