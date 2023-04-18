#include <fctnl.h>
#include "get_next_line.h"
#include "libft.h"

typedef struct	s_tile
{
	int id;
}		t_tile;

typedef struct	s_map
{
	int	sizeX;
	int sizeY;

	t_tile* tiles;
}			t_map;

t_map	*loadmap(const char* path)
{
	int		fd;
	t_list	*lst;
	int		i;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		while (line[i])
		{
			if (line[i])
		}
		line = get_next_line(fd);
	}
}
