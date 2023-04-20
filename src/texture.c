#include "texture.c"

static void	pixel_put(t_texture data, int x, int y, int color)
{
	char	*dst;

	dst = data->data + (y * data->line_size + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

static int	pixel_get(t_texture data, int x, int y)
{
	char	*dst;
	dst = data->data + (y * data->line_size + x * (data->bpp / 8));
	return (*(unsigned int*)dst);
}


t_texture create_texture(void *mlx, int width, int height)
{
	t_texture tex;
	
	tex.width = width;
	tex.height = height;
	tex.img = mlx_new_image(mlx, width, height);
	tex.data = mlx_get_data_addr(tex.img, &tex.bbp, &tex.line_size, &tex.endian);
	return (tex);
}

t_texture copy_texture(void *mlx, t_texture tex, t_vec start, t_vec end, int scale)
{
	t_vec size;
	t_texture new;
	t_vec pos;
	
	size = vsub(end, start);
	new = create_texture(mlx, size.x * scale, size.y * scale);
	while (pos.y < size.y * scale)
	{
		while (pos.x < size.x * scale)
		{
			pixel_put(new, pos.x, pos.y, pixel_get(tex, pos.x / scale, pox.y / scale));
		}
	}
	return (new);	
}

t_texture load_texture(void *mlx, const char *path)
{
	t_texture tex;

	tex.img = mlx_xpm_file_to_image(mlx, path, &tex.width, &tex.height);
	tex.data = mlx_get_data_addr(tex.img, &tex.bbp, &tex.line_size, &tex.endian);
	return (tex);
}
