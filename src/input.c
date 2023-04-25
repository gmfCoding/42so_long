/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:05:26 by clovell           #+#    #+#             */
/*   Updated: 2023/04/25 17:06:07 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "state.h"
#include "ft_printf.h"
#include "input.h"
#include "movement.h"

int	on_input_press(int key, t_gamestate *state)
{
	ft_printf("press:%d\n", key);
	mv_process_input(key, 1, &state->move);
	return (0);
}

int	on_input_release(int key, t_gamestate *state)
{
	ft_printf("release:%d\n", key);
	mv_process_input(key, 0, &state->move);
	return (0);
}
