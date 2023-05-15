/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:49:28 by clovell           #+#    #+#             */
/*   Updated: 2023/05/15 19:49:56 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTROY_H
# define DESTROY_H

# include "map.h"
# include "state.h"
# include "theme.h"
# include "texture.h"

void	destroy_map(t_map **map);
void	destroy_texture(t_gamestate *gs, t_texture tex);
void	destroy_theme(t_gamestate *gs, t_themeinfo **theme);
void	destroy_state(t_gamestate *state);
#endif
