/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:51:06 by clovell           #+#    #+#             */
/*   Updated: 2023/05/02 08:18:30 by clovell          ###   ########.fr       */
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
