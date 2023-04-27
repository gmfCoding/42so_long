/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:15:01 by clovell           #+#    #+#             */
/*   Updated: 2023/04/27 12:06:11 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STATE_H
# define STATE_H
# include "libft.h"
# include "texture.h"
# include "map.h"
# include "movement.h"
# include "theme.h"

typedef struct s_gamestate
{
	void		*mlx;
	void		*win;
	int			logfile;

	int			w_width;
	int			w_height;

	void		*tile_images[TILE_COUNT];

	t_list		*sprites;	
	t_map		*map;
	t_sprite	*player;
	t_pmove		move;
	t_themeinfo	*theme;
}			t_gamestate;
#endif
