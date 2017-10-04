/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:15:38 by mtacnet           #+#    #+#             */
/*   Updated: 2017/09/01 14:16:10 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	cpy_lst(t_elem **lst_dest, t_elem **lst_src)
{
	t_elem		*head;

	head = (*lst_src);
	while ((*lst_src) != NULL)
	{
		push_elem(lst_dest, (*lst_src)->content);
		(*lst_src) = (*lst_src)->next;
	}
	(*lst_src) = head;
}
