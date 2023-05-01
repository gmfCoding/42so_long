/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:48:44 by clovell           #+#    #+#             */
/*   Updated: 2023/05/01 19:40:53 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	draw_theme(t_gamestate *gs)
{
	int			*i;
	void		*mlx;
	void		*win;
	t_tiletex	*tile;

	mlx = gs->mlx;
	win = gs->win;
	i = 0;
	while (x < TILE_COUNT)
	{
		if (gs->theme->tiletexs[x].subquad)
		{
			tile = gs->theme->tiletexs[i];
			mlx_put_image_to_window(mlx, win, tile.tl.img, 0, x * 96);
			mlx_put_image_to_window(mlx, win, tile.tr.img, 48, x * 96);
			mlx_put_image_to_window(mlx, win, tile.bl.img, 0, x * 96 + 48);
			mlx_put_image_to_window(mlx, win, tile.br.img, 48, x * 96 + 48);
		}
		x++;
	}
}

void	push_debugtex(t_gamestate *gs, int x, int y)
{
	static t_texture	tex;

	if (!tex.img)
		tex = load_texture(gs, "assets/debug.xpm");
	mlx_put_image_to_window(gs->mlx, gs->win, tex.img, x, y);
}