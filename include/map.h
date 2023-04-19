#define TILE_PLAYER		0
#define TILE_WALL		1
#define TILE_FLOOR		2
#define TILE_EXIT		3
#define TILE_COLLECT	4

typedef struct	s_map
{
	int	sizeX;
	int sizeY;

	int* tiles;
}			t_map;
t_map	*loadmap(const char* path);
