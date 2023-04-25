/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:12:12 by clovell           #+#    #+#             */
/*   Updated: 2023/04/25 16:12:30 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "texture.h"
#include "libft.h"

t_sprite	*instance(t_texture tex, t_vec pos)
{
	t_sprite	*sprite;

	sprite = ft_calloc(1, sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->tex = tex;
	sprite->pos = pos;
	return (sprite);
}
