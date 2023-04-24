/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:43:15 by clovell           #+#    #+#             */
/*   Updated: 2023/04/24 17:00:46 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MOVEMENT_H
# define MOVEMENT_H

#  ifndef MOVE_SPEED
#   define MOVE_SPEED 2
#  endif

typedef struct	s_pmove
{
	int	left;
	int	right;
	int	up;
	int	down;
}				t_pmove;

int	mv_process_input(t_pmove *move);
int	mv_process_frame(t_sprite *sprite, t_pmove *move);
#endif