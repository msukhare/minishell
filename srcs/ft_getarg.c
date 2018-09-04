/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:29:49 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/23 13:23:43 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_getsizewrd(t_cmd **begin_list)
{
	int		size;
	t_cmd	*tmp;

	size = 0;
	tmp = *begin_list;
	while (tmp && tmp->cara != ' ' && tmp->cara != ';')
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

static int	ft_getsizearg(t_cmd **begin_list)
{
	int		size;
	t_cmd	*tmp;
	int		ag;

	size = 0;
	tmp = *begin_list;
	ag = 1;
	while (tmp && tmp->cara != ';')
	{
		if (tmp->cara == ' ' || tmp->cara == '\t')
			ag = 1;
		else if (ag == 1)
		{
			size++;
			ag = 0;
		}
		tmp = tmp->next;
	}
	return (size);
}

static char	**ft_creat_tab_forarg(t_cmd **begin_list)
{
	char	**to_ret;

	if (!(to_ret = (char **)malloc(sizeof(char*) *\
					(ft_getsizearg(begin_list) + 2))))
		return (NULL);
	if (!(to_ret[0] = (char*)malloc(sizeof(char) * 2)))
	{
		free(to_ret);
		return (NULL);
	}
	to_ret[0][0] = ' ';
	to_ret[0][1] = '\0';
	return (to_ret);
}

static void	ft_dellink(t_cmd **begin_list)
{
	t_cmd	*to_free;

	to_free = *begin_list;
	(*begin_list) = (*begin_list)->next;
	free(to_free);
}

char		**ft_getarg(t_cmd **begin_list)
{
	char	**to_ret;
	int		j;

	j = 1;
	if (!(to_ret = ft_creat_tab_forarg(begin_list)))
		return (NULL);
	while ((*begin_list) && (*begin_list)->cara != ';')
	{
		if ((*begin_list)->cara != ' ' && (*begin_list)->cara != '\t')
		{
			if (!(to_ret[j] = (char*)malloc(sizeof(char) * \
					(ft_getsizewrd(begin_list) + 1))))
			{
				ft_freetab(to_ret);
				return (NULL);
			}
			ft_cpag(to_ret[j], begin_list);
			j++;
		}
		else
			ft_dellink(begin_list);
	}
	to_ret[j] = 0;
	return (to_ret);
}
