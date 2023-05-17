/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:02:06 by clovell           #+#    #+#             */
/*   Updated: 2023/05/17 21:47:59 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_printf.h"
#include "error.h"

void	print_errors(t_error error)
{
	if (error == E_NONE)
		return ;
	else
		ft_printf("Error\n");
	if (error & E_EXIT)
		ft_printf("Issue occured with exit tiles, 1 and only 1 must exist!\n");
	if (error & E_POS)
		ft_printf("Issue occured with start tile, 1 and only 1 must exist!\n");
	if (error & E_COLL)
		ft_printf("No collectables exists, cannot load map!\n");
	if (error & E_BOUND)
		ft_printf("Map leaks into the void, cannot load map!\n");
	if (error & E_FILE)
		ft_printf("Map file cannot be read!\n");
}

void	exit_error(t_error error)
{
	print_errors(error);
	exit(1);
}
