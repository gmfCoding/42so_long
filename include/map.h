/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:21:37 by clovell           #+#    #+#             */
/*   Updated: 2023/04/19 20:22:05 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# define TILE_PLAYER		0
# define TILE_WALL		1
# define TILE_FLOOR		2
# define TILE_EXIT		3
# define TILE_COLLECT	4

typedef struct s_tile
{
	int id;
	int collectable;
}

typedef struct	s_map
{
	int	sizeX;
	int sizeY;

	int start_pos;

	int* tiles;
}			t_map;

t_tile	tile_new(int id, int collectable);
t_map	*loadmap(const char* path);
#endif
