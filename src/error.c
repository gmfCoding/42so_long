/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:02:06 by clovell           #+#    #+#             */
/*   Updated: 2023/05/11 13:09:38 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_printf.h"
#include "error.h"

void	print_errors(t_error error)
{
	if (error == E_NONE)
		return ;
	if (error & E_EXIT)
		ft_printf("No exit tile exists, cannot load map!\n");
	if (error & E_COLL)
		ft_printf("No collectables exists, cannot load map!\n");
	if (error & E_POS)
		ft_printf("No starting position exists, cannot load map!\n");
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
