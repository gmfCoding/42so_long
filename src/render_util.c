#include <mlx.h>
#include "vector.h"
#include "texture.h"
#include "state.h"

void	push_sprite(t_gamestate *gs, t_sprite *sprite)
{
	t_vec		pos;
	t_texture	tex;
	void		*mlx;
	void		*win;

	pos = sprite->pos;
	tex = sprite->tex;
	mlx = gs->mlx;
	win = gs->win;
	mlx_put_image_to_window(mlx, win, tex.img, pos.x, pos.y);
}

void	push_tex(t_gamestate *gs, t_texture tex, t_vec pos)
{
	void		*mlx;
	void		*win;

	mlx = gs->mlx;
	win = gs->win;
	mlx_put_image_to_window(mlx, win, tex.img, pos.x, pos.y);
}
