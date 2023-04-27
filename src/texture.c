/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:11:47 by clovell           #+#    #+#             */
/*   Updated: 2023/04/27 16:38:21 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "texture.h"
#include "vectormath.h"
#include <mlx.h>

static void	pxput(t_texture data, int x, int y, int color)
{
	char	*dst;

	dst = data.data + (y * data.line_size + x * (data.bpp / 8));
	*(unsigned int *)dst = color;
}

static int	pxget(t_texture data, int x, int y)
{
	char	*dst;

	dst = data.data + (y * data.line_size + x * (data.bpp / 8));
	return (*(int *)dst);
}

t_texture	create_texture(void *mlx, int width, int height)
{
	t_texture	t;

	t.width = width;
	t.height = height;
	t.img = mlx_new_image(mlx, width, height);
	t.data = mlx_get_data_addr(t.img, &t.bpp, &t.line_size, &t.endian);
	return (t);
}

t_texture	copy_tex(void *mlx, t_texture tex, const t_vec reg[2], int scale)
{
	t_texture	new;
	t_vec		size;
	t_vec		pos;
	t_vec		o;
	int			col;

	o = reg[0];
	size = vsub(reg[1], reg[0]);
	new = create_texture(mlx, size.x * scale, size.y * scale);
	pos.y = 0;
	while (pos.y < size.y * scale)
	{
		pos.x = 0;
		while (pos.x < size.x * scale)
		{
			col = pxget(tex, o.x + pos.x / scale, o.y + pos.y / scale);
			pxput(new, pos.x, pos.y, col);
			pos.x++;
		}
		pos.y++;
	}
	return (new);
}

t_texture	load_texture(void *mlx, const char *path)
{
	t_texture	t;

	t.img = mlx_xpm_file_to_image(mlx, path, &t.width, &t.height);
	t.data = mlx_get_data_addr(t.img, &t.bpp, &t.line_size, &t.endian);
	return (t);
}
