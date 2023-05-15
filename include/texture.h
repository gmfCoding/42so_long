/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:13:28 by clovell           #+#    #+#             */
/*   Updated: 2023/05/15 14:59:26 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "vector.h"

typedef struct s_texture
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
}				t_texture;

t_texture	create_texture(void *mlx, int width, int height);

t_texture	copy_tex(void *mlx, t_texture tex, const t_vec reg[2], int scale);

/* create a copy of 'tex' that has been rotated by 90-deg * 'rot' */
t_texture	rotate_tex(void *mlx, t_texture tex, int rot);

t_texture	load_texture(void *mlx, char *path);

#endif
