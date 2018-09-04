/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createnv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:10:56 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/23 13:36:48 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env		*ft_creatvar(char *str)
{
	t_env	*new_elem;

	if (!(new_elem = (t_env*)malloc(sizeof(t_env) * 1)))
		return (NULL);
	if (!(new_elem->var = ft_strdup(str)))
	{
		free(new_elem);
		return (NULL);
	}
	new_elem->next = NULL;
	return (new_elem);
}

void		ft_freelist(t_env *begin_list)
{
	t_env	*tmp;

	while (begin_list)
	{
		tmp = begin_list;
		begin_list = begin_list->next;
		free(tmp->var);
		free(tmp);
	}
}

t_env		*ft_createnv(char **str)
{
	t_env	*begin_list;
	t_env	*tmp;
	int		i;

	begin_list = NULL;
	i = 0;
	if (!(begin_list = ft_creatvar(" ")))
		return (NULL);
	tmp = begin_list;
	while (str[i])
	{
		if (!(tmp->next = ft_creatvar(str[i])))
		{
			ft_freelist(begin_list);
			return (NULL);
		}
		i++;
		tmp = tmp->next;
	}
	return (begin_list);
}
