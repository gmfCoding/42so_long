/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:21:28 by clovell           #+#    #+#             */
/*   Updated: 2023/05/22 15:06:05 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_error
{
	E_NONE = 0,
	E_EXIT = 1,
	E_COLL = 2,
	E_POS = 4,
	E_BOUND = 8,
	E_PATH = 16,
	E_FILE = 32,
	E_WIDTH = 64,
	E_SYMB = 128
}			t_error;

void	print_errors(t_error error);
void	exit_error(t_error error);

#endif
