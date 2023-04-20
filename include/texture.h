typedef struct	s_texture
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
}				t_texture;

t_texture create_texture(void *mlx, int width, int height);

t_texture copy_texture(void *mlx, t_texture tex, t_vec start, t_vec end, int scale);

t_texture load_texture(void *mlx, const char *path);
