/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:10:11 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/20 09:15:13 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_env	*ft_findtodel(t_env *env, char *str)
{
	t_env		*tmp;

	tmp = env;
	while (tmp && (ft_strncmp(tmp->var, str, ft_strlen(str)) != 0))
		tmp = tmp->next;
	return (tmp);
}

void			ft_unsetenv(char **arg, t_env **env)
{
	int			i;
	t_env		*to_del;
	t_env		*tmp;

	i = 1;
	while (arg[i])
	{
		if ((to_del = ft_findtodel(*env, arg[i])))
		{
			if (to_del == (*env))
				(*env) = to_del->next;
			else
			{
				tmp = (*env);
				while (tmp->next != to_del)
					tmp = tmp->next;
				tmp->next = to_del->next;
			}
			free(to_del->var);
			free(to_del);
		}
		i++;
	}
}
