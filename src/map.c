/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:27:24 by clovell           #+#    #+#             */
/*   Updated: 2023/05/12 20:25:56 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lst_extra.h"
#include "libft.h"
#include "map.h"
#include "vector.h"
#include <stdlib.h>

static t_tile	make_tile(char type, int x, int y, t_map *map)
{
	t_tile	def;

	def = (new_tile(TILE_FLOOR));
	if (type == 'P')
	{
		map->start = vnew(x, y);
		def = (new_s_tile(TILE_FLOOR));
	}
	else if (type == 'E')
	{
		map->exit = vnew(x, y);
		def = (new_e_tile(TILE_FLOOR));
	}
	else if (type == '1')
		def = (new_tile(TILE_WALL));
	else if (type == 'C')
		def = (new_c_tile(TILE_FLOOR, 1));
	return (def);
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
			if (type == '\n')
				break ;
			tile = make_tile(type, x, y, map);
			map->tiles[y * map->size_x + x] = tile;
			x++;
		}
		lst = lst->next;
		y++;
	}
}

t_tile	*get_tile_ptr(int x, int y, t_map *map)
{
	return (&(map->tiles[map->size_x * y + x]));
}

t_tile	get_tile(int x, int y, t_map *map)
{
	return (map->tiles[map->size_x * y + x]);
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
	map->size_x = ft_strlen(lst->next->next->content) - 1;
	map->tiles = ft_calloc(map->size_x * map->size_y, sizeof(t_tile));
	set_tiles(lst->next, map);
	ft_lstclear(&lst->next, free);
	free(lst);
	return (map);
}
