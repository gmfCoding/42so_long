/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:54:42 by clovell           #+#    #+#             */
/*   Updated: 2023/04/24 17:22:45 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "input.h"
#include "render.h"
#include "vectormath.h"
#include "movement.h"

int mv_process_input(int key, int press, t_pmove	*move)
{
	int test = KEY_W;
	if (key == KEY_W)
		move->up = press;
	if (key == KEY_A)
		move->left = press;
	if (key == KEY_S)
		move->down = press;
	if (key == KEY_D)
		move->right = press;
	return (0);
}

int mv_process_frame(t_sprite *sprite, t_pmove *move)
{
	t_vec dir;
	t_vecd speed;

	speed = 1.0 / FRAMERATE * MOVE_SPEED;

	if (move->up)
		dir.y += -1;
	if (move->down)
		dir.y += 1;
	if (move->right)
		dir.x += 1;
	if (move->left)
		dir.x += -1;

	dir = vmuls(vnorm(dir), speed);

	sprite->pos = vadd(sprite->pos, dir);
	return (0);
}
