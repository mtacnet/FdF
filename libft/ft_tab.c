/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:30:32 by mtacnet           #+#    #+#             */
/*   Updated: 2017/09/01 14:23:22 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**list_to_tab(t_elem **lst)
{
	int			i;
	size_t		j;
	char		**tab;
	t_elem		*head;

	i = 0;
	j = 0;
	tab = NULL;
	head = (*lst);
	while ((*lst) != NULL)
	{
		j++;
		(*lst) = (*lst)->next;
	}
	(*lst) = head;
	if (!(tab = ft_memalloc(sizeof(*tab) * (j + 1))))
		exit(EXIT_FAILURE);
	while ((*lst) != NULL)
	{
		tab[i] = (*lst)->content;
		(*lst) = (*lst)->next;
		i++;
	}
	(*lst) = head;
	return (tab);
}

void	tab_to_list(t_elem **lst, char **tab)
{
	int		i;

	i = 0;
	while (tab[i] && tab[i][0] != '\0')
	{
		push_elem(lst, tab[i]);
		i++;
	}
}

void	supp_elem_tab(char **tab, int value)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] && tab[i][0] != '\0')
		i++;
	if (value >= i)
		return ;
	else
	{
		while (j < i)
		{
			tab[j] = tab[j + 1];
			j++;
		}
	}
	return ;
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] != NULL)
		{
			ft_strdel(&(tab[i]));
			i++;
		}
		else
			i++;
	}
	free(tab);
	tab = NULL;
}
