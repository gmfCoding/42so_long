/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:07:19 by clovell           #+#    #+#             */
/*   Updated: 2023/05/02 08:18:05 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RENDER_H
# define RENDER_H
# include "state.h"
# include "texture.h"

# ifndef FRAMERATE
#  define FRAMERATE 70.0f
# endif

int		on_frame(t_gamestate *param);
void	push_tex(t_gamestate *gs, t_texture tex, t_vec pos);
void	push_tile(t_gamestate *gs, t_vec pos);

#endif
