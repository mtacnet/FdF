/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:16:53 by mtacnet           #+#    #+#             */
/*   Updated: 2017/09/18 11:18:55 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int mode)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (mode == 1 && s1)
		ft_strdel(&s1);
	else if (mode == 2 && s2)
		ft_strdel(&s2);
	else if (mode != 1 && mode != 2 && s1 && s2)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (tmp);
}
