/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:14:44 by mtacnet           #+#    #+#             */
/*   Updated: 2017/09/01 14:15:20 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	view_list(t_elem **lst)
{
	t_elem		*head;

	head = (*lst);
	while ((*lst) != NULL)
	{
		ft_putendl((*lst)->content);
		(*lst) = (*lst)->next;
	}
	(*lst) = head;
}
