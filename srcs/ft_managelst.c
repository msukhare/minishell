/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managelst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:28:56 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/20 12:42:34 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd		*ft_creatlist(char buff, t_cmd *back_lst)
{
	t_cmd	*new_elem;

	if (!(new_elem = (t_cmd*)malloc(sizeof(t_cmd))))
		return (NULL);
	new_elem->cara = buff;
	new_elem->next = NULL;
	new_elem->back = back_lst;
	return (new_elem);
}

void		ft_dellist(t_cmd **begin_list)
{
	t_cmd	*tmp;

	while (*begin_list)
	{
		tmp = (*begin_list);
		(*begin_list) = (*begin_list)->next;
		free(tmp);
	}
	(*begin_list) = NULL;
}

int			ft_lstlen(t_env *bg_lst)
{
	int		i;

	i = 0;
	while (bg_lst)
	{
		i++;
		bg_lst = bg_lst->next;
	}
	return (i);
}

void		ft_dellst(t_env *begin_list)
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

t_env		*ft_cpylst(t_env *env)
{
	t_env	*begin_list;
	t_env	*tmp;

	begin_list = NULL;
	if (!(begin_list = ft_creatvar(" ")))
		return (NULL);
	tmp = begin_list;
	while (env)
	{
		if (!(tmp->next = ft_creatvar(env->var)))
			return (NULL);
		tmp = tmp->next;
		env = env->next;
	}
	return (begin_list);
}
