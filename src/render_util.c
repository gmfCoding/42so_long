/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:24:09 by clovell           #+#    #+#             */
/*   Updated: 2023/05/02 08:20:01 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "vector.h"
#include "texture.h"
#include "state.h"

void	push_tex(t_gamestate *gs, t_texture tex, t_vec pos)
{
	void		*mlx;
	void		*win;

	mlx = gs->mlx;
	win = gs->win;
	mlx_put_image_to_window(mlx, win, tex.img, pos.x, pos.y);
}
