/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:28:14 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/23 13:09:37 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_getszcmd(t_cmd **begin_list)
{
	int		size;
	t_cmd	*tmp;

	size = 0;
	tmp = *begin_list;
	while (tmp && (tmp->cara == ' ' || tmp->cara == '\t'))
		tmp = tmp->next;
	while (tmp && tmp->cara != ' ' && tmp->cara != ';' && tmp->cara != '\t')
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

char		*ft_getcmd(t_cmd **begin_list)
{
	char	*to_r;
	int		j;
	t_cmd	*tmp;

	j = 0;
	if (!(to_r = (char *)malloc(sizeof(char) * (ft_getszcmd(begin_list) + 1))))
		return (NULL);
	while ((*begin_list) && ((*begin_list)->cara == ' ' ||
			(*begin_list)->cara == '\t'))
	{
		tmp = (*begin_list);
		(*begin_list) = (*begin_list)->next;
		free(tmp);
	}
	while ((*begin_list) && (*begin_list)->cara != ' ' &&
			(*begin_list)->cara != ';' && (*begin_list)->cara != '\t')
	{
		tmp = (*begin_list);
		to_r[j] = (*begin_list)->cara;
		j++;
		(*begin_list) = (*begin_list)->next;
		free(tmp);
	}
	to_r[j] = '\0';
	return (to_r);
}
