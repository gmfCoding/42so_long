/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:54:42 by clovell           #+#    #+#             */
/*   Updated: 2023/05/01 19:49:31 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "input.h"
#include "render.h"
#include "vectormath.h"
#include "movement.h"
#include <stdio.h>

/*
int	mv_process_frame(t_sprite *sprite, t_pmove *move)
{
	t_vec	dir;
	t_vecd	speed;

	speed = 1.0 / FRAMERATE * MOVE_SPEED;
	dir.x = 0;
	dir.y = 0;
	if (move->up)
		dir.y += -1;
	if (move->down)
		dir.y += 1;
	if (move->right)
		dir.x += 1;
	if (move->left)
		dir.x += -1;
	dir = vmuls(vnorm(dir), speed);
	printf("%f, %f, F:%f, S:%d\n", dir.x, dir.y, FRAMERATE, MOVE_SPEED);
	sprite->pos = vadd(sprite->pos, dir);
	return (0);
}*/
