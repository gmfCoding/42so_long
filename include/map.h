/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:21:37 by clovell           #+#    #+#             */
/*   Updated: 2023/04/19 21:44:24 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# define TILE_PLAYER	0
# define TILE_WALL		1
# define TILE_FLOOR		2
# define TILE_EXIT		3
# define TILE_COLLECT	4

typedef struct s_tile
{
	int id;
	int collectable;
}				t_tile

typedef struct	s_map
{
	int	size_x;
	int size_y;

	t_vec start;
	t_vec exit;

	t_tile* tiles;
}			t_map;

t_tile	tile_new(int id, int collectable);
t_map	*load_map(const char* path);
#endif
