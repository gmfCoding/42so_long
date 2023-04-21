typedef struct	s_gamestate
{
	void		*mlx;
	void		*win;
	
	int			w_width;
	int			w_height;

	void		*tile_images[TILE_COUNT];
	
	t_list		*sprites;	
	t_map		*map;
	t_sprite	*player;
}			t_gamestate;


