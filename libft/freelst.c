/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:03:13 by mtacnet           #+#    #+#             */
/*   Updated: 2017/09/01 14:06:12 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	freelst(t_elem **lst)
{
	t_elem		*list;
	t_elem		*tmp;

	list = (*lst);
	while (list)
	{
		tmp = list->next;
		ft_strdel(&(list->content));
		free(list);
		list = tmp;
	}
	(*lst) = NULL;
}
