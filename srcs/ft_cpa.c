/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:09:51 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/23 13:00:30 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_cpag(char *dest, t_cmd **begin_list)
{
	int		i;
	t_cmd	*tmp;

	i = 0;
	while ((*begin_list) && (*begin_list)->cara != ' ' &&
			(*begin_list)->cara != ';' && (*begin_list)->cara != '\t')
	{
		dest[i] = (*begin_list)->cara;
		tmp = (*begin_list);
		(*begin_list) = (*begin_list)->next;
		free(tmp);
		i++;
	}
	dest[i] = '\0';
}
