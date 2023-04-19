#include "lst_extra.h"
#include "libft.h"
#include "map.h"

t_map	*loadmap(const char* path)
{
	t_list	*lst;
	t_map	*map;
	int x;
	int y;

	y = 0;
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	lst = ft_lst_readfile(path);
	map->sizeY = (int)lst->content;
	lst = lst->next;
	map->sizeX = ft_strlen(lst->next->content) - 1;
	map->tiles = ft_calloc(map->sizeX * map->sizeY, sizeof(int));
	while (lst->content)
	{
		x = 0;
		while (((char *)(lst->content))[x])
		{
			if (((char *)(lst->content))[x] == '#')
				map->tiles[y * map->sizeX + x] = TILE_WALL;
			else if (((char *)(lst->content))[x] == 'P')
				map->tiles[y * map->sizeX + x] = TILE_PLAYER;
			else if (((char *)(lst->content))[x] == '0')
				map->tiles[y * map->sizeX + x] = TILE_FLOOR;
			else if (((char *)(lst->content))[x] == 'C')
				map->tiles[y * map->sizeX + x] = TILE_COLLECT;
			else if (((char *)(lst->content))[x] == 'E')
				map->tiles[y * map->sizeX + x] = TILE_EXIT;
			x++;
		}
		lst = lst->next;
		y++;
	}
	return (map);
}
