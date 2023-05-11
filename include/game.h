/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:31:38 by clovell           #+#    #+#             */
/*   Updated: 2023/05/11 14:42:36 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "input.h"
# include "state.h"

int		on_input(int key, t_gamestate *state);
void	on_tile(t_gamestate *state, t_tile *tile, int x, int y);

#endif
