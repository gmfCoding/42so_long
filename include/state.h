#ifndef STATE_H
# define STATE_H
# include "libft.h"
# include "texture.h"
# include "map.h"

typedef struct	s_gamestate
{
	void		*mlx;
	void		*win;
	int			logfile;
	
	int			w_width;
	int			w_height;

	void		*tile_images[TILE_COUNT];
	
	t_list		*sprites;	
	t_map		*map;
	t_sprite	*player;
	t_pmove		move;
}			t_gamestate;
#endif
