#include "map.h"

t_tile	new_tile(int id, int collectable)
{
	t_tile tile;
	tile.id = id;
	tile.collectale = collectable;
}
