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
		ft_printf("Map leaks into the void, cannot load map!");
}
