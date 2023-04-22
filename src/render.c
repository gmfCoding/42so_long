/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:53:37 by clovell           #+#    #+#             */
/*   Updated: 2023/04/21 18:53:40 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"


static void push_sprite(t_gamestate *gs, t_sprite *sprite)
{
	t_vec		pos;
	t_texture	*tex;
	void		*mlx;
	void		*win;

	pos = sprite->pos;
	tex = sprite->tex;
	mlx = gs->mlx;
	win = gs->win;
	mlx_put_image_to_window(mlx, win, tex.img, pos.x, pos.y);
}

int	frame(void *param)
{
	t_gamestate *gs;
	t_list	*sp_next;

	gs = (t_gamestate*)param;
	mlx_clear_window(gs->mlx, gs->win);
	sp_next = gs->sprites;
	while (sp_next->next)
	{
		push_sprite(gs, sp_next);
		sp_next = sp_next->next;
	}
	return (0);
}
