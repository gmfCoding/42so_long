/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:15:01 by clovell           #+#    #+#             */
/*   Updated: 2023/05/10 13:38:32 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STATE_H
# define STATE_H
# include "libft.h"
# include "texture.h"
# include "map.h"
# include "theme.h"

typedef struct s_gamestate
{
	void		*mlx;
	void		*win;

	int			w_width;
	int			w_height;

	int			moves;
	int			collected;
	t_map		*map;
	t_vec		pos;
	t_themeinfo	*theme;
}			t_gamestate;

#endif
