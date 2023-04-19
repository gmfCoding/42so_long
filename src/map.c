/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:27:24 by clovell           #+#    #+#             */
/*   Updated: 2023/04/19 23:22:58 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lst_extra.h"
#include "libft.h"
#include "map.h"


static t_tile set_tile(char type, int x, int y, t_map *map)
{
	if (type == 'P')
		map->start = vnew((t_vecd)x, (t_vecd)y); 
	else if (type == 'E')
		map->exit = vnew((t_vecd)x, (t_vecd)y);
	else if (type == '#')
		return (new_tile(TILE_WALL));
	else if (type == 'C')
		return (new_c_tile(TILE_FLOOR, 1));
	return (new_tile(TILE_FLOOR));
}

static void	set_tiles(t_list *lst, t_map *map)
{
	int x;
	int y;

	y = 0;
	while (lst->content)
	{
		x = 0;
		while (((char *)(lst->content))[x])
		{
			map->tiles[y * map->size_x + x] = set_tile(((char *)lst->content)[x], x, y, map);
			x++;
		}
		lst = lst->next;
		y++;
	}
}

t_map	*load_map(const char* path)
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
	map->tiles = ft_calloc(map->size_x * map->size_y, sizeof(int));
	set_tiles(lst, map);
	return (map);
}
