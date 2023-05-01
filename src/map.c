/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:27:24 by clovell           #+#    #+#             */
/*   Updated: 2023/05/02 07:20:44 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lst_extra.h"
#include "libft.h"
#include "map.h"

t_tile	*get_tile_ptr(int x, int y, t_map *map)
{
	return &(map->tiles[map->size_x * y + x]);
}

t_tile	get_tile(int x, int y, t_map *map)
{
	return (map->tiles[map->size_x * y + x]);
}

static void	set_tiles(t_list *lst, t_map *map)
{
	int		x;
	int		y;
	t_tile	tile;
	char	type;

	y = 0;
	while (lst->content)
	{
		x = 0;
		while (((char *)(lst->content))[x])
		{
			type = ((char *)lst->content)[x];
			tile = (new_tile(TILE_FLOOR));
			if (type == 'P')
				map->start = vnew((t_vecd)x, (t_vecd)y);
			else if (type == 'E')
				map->exit = vnew((t_vecd)x, (t_vecd)y);
			else if (type == '1')
				tile = (new_tile(TILE_WALL));
			else if (type == 'C')
				tile = (new_c_tile(TILE_FLOOR, 1));
			map->tiles[y * map->size_x + x] = tile;
			x++;
		}
		lst = lst->next;
		y++;
	}
}

int	bounds(t_map *map, int x, int y)
{
	int	boundx;
	int	boundy;

	boundx = (x >= 0 && x < map->size_x);
	boundy = (y >= 0 && y < map->size_x);
	return (boundx && boundy);
}

t_map	*load_map(const char *path)
{
	t_list	*lst;
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	lst = ft_lst_readfile(path);
	map->size_y = (int)lst->content;
	lst = lst->next;
	map->size_x = ft_strlen(lst->next->content) - 1;
	map->tiles = ft_calloc(map->size_x * map->size_y, sizeof(t_tile));
	set_tiles(lst, map);
	return (map);
}
