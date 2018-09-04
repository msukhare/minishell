/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:52:02 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/23 16:32:29 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_cmptvars(char **arg, int *end)
{
	int		size;

	size = 0;
	while (arg[size] && ft_check_var(arg[size]) == 1)
	{
		size++;
		(*end)++;
	}
	return (size);
}

char		**ft_splitarg(char **arg, int *end)
{
	char	**to_ret;
	int		i;
	int		size;

	size = 1;
	i = 0;
	while (arg[size] && ft_check_var(arg[size]) == 1)
		size++;
	if (!(to_ret = (char**)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(to_ret[i] = ft_strdup(arg[i])))
		{
			ft_freetab(to_ret);
			return (NULL);
		}
		i++;
		(*end)++;
	}
	to_ret[i] = 0;
	return (to_ret);
}

char		**ft_creat_arg_env(char **arg, int end)
{
	int		size;
	char	**to_ret;
	int		i;

	size = end;
	i = 0;
	while (arg[size])
		size++;
	if (!(to_ret = (char**)malloc(sizeof(char *) * (size + 2))))
		return (NULL);
	if (!(to_ret[i++] = ft_strdup(" ")))
	{
		free(to_ret);
		return (NULL);
	}
	while (arg[end])
	{
		if (!(to_ret[i++] = ft_strdup(arg[end++])))
		{
			ft_freetab(to_ret);
			return (NULL);
		}
	}
	to_ret[i] = 0;
	return (to_ret);
}

int			ft_exec_cpy_env(t_env *env_cpy, char **arg, int end)
{
	char	*cmd;
	char	**new_arg;

	if (!(cmd = ft_strdup(arg[end++])))
	{
		ft_dellst(env_cpy);
		return (-1);
	}
	if (!(new_arg = ft_creat_arg_env(arg, end)))
	{
		free(cmd);
		ft_dellst(env_cpy);
		return (-1);
	}
	ft_execbin(cmd, env_cpy, new_arg);
	free(cmd);
	ft_freetab(new_arg);
	ft_dellst(env_cpy);
	return (0);
}

int			ft_env(t_env *env, char **arg)
{
	t_env	*tmp;
	char	**vars;
	int		end;

	end = 0;
	if (!(tmp = ft_cpylst(env)))
		return (-1);
	if (ft_lentab(arg) <= 1)
		ft_printenv(tmp);
	else
	{
		if (!(vars = ft_splitarg(arg, &end)) || (ft_setenv(tmp, vars)) == -1)
		{
			ft_dellst(tmp);
			(vars) ? ft_freetab(vars) : 0;
			return (-1);
		}
		ft_freetab(vars);
		if (arg[end])
			return (ft_exec_cpy_env(tmp, arg, end));
		else
			ft_printenv(tmp);
	}
	ft_dellst(tmp);
	return (0);
}
