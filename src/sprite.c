#include "texture.h"
#include <stddef.h>

t_sprite	*instance(t_texture tex, t_vec pos)
{
	t_sprite *sprite;

	sprite = ft_calloc(1, sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->tex = tex;
	sprite->pos = pos;
	return (sprite);
}
