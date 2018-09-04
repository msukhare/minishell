/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:17:35 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/21 10:53:42 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_check_var(char *str)
{
	int		i;
	int		equal;

	equal = 0;
	i = 0;
	while (str[i])
	{
		if (equal == 0 && i >= 1 && str[i] == '=')
			equal = 1;
		i++;
	}
	return (equal);
}

static int	ft_str_trytoput(t_env *tmp, char *var)
{
	if ((ft_strccmp(tmp->var, var, '=')) == 0)
	{
		free(tmp->var);
		if (!(tmp->var = ft_strdup(var)))
			return (-1);
		return (1);
	}
	else if (tmp->next == NULL)
	{
		if (!(tmp->next = ft_creatvar(var)))
			return (-1);
		return (1);
	}
	return (0);
}

int			ft_setenv(t_env *env, char **arg)
{
	int		i;
	t_env	*tmp;
	int		end;

	i = 0;
	while (arg[i])
	{
		if ((ft_check_var(arg[i])) == 1)
		{
			tmp = env;
			end = 0;
			while (tmp && end == 0)
			{
				if ((end = ft_str_trytoput(tmp, arg[i])) == -1)
					return (-1);
				tmp = tmp->next;
			}
		}
		i++;
	}
	return (0);
}
