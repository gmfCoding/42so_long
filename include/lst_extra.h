/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_extra.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:13:32 by clovell           #+#    #+#             */
/*   Updated: 2023/04/25 17:17:45 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LST_EXTRA_H
# define LST_EXTRA_H
# include "libft.h"

/*	Loads a file at the given 'path', into a linked list
 *	RETURNS:
 *	A linked list where the first node is the line count,
 *	Each remaining node contains a seperate line,
 *	Last nodes content is NULL marking the EOF.
 *	NOTE: The line count store at the first node should be: 
 *	(ft_listsize(lst) - 2)
 */
t_list	*ft_lst_readfile(const char *path);
#endif
