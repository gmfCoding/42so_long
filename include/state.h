/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:15:01 by clovell           #+#    #+#             */
/*   Updated: 2023/05/11 14:44:54 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STATE_H
# define STATE_H
# include "libft.h"
# include "texture.h"
# include "map.h"
# include "theme.h"

typedef void	(*t_tile_f)(t_gamestate *state, t_tile *tile, int x, int y);
typedef int		(*t_state_f)(t_gamestate *state);

typedef struct s_gamestate
{
	void		*mlx;
	void		*win;

	int			w_width;
	int			w_height;

	char		*map_path;

	int			moves;
	int			collected;

	t_tile_f	tile_event;
	t_state_f	quit_event;

	t_map		*map;
	t_vec		pos;
	t_themeinfo	*theme;
}			t_gamestate;

#endif
