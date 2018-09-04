/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getforcd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:27:34 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/23 11:29:07 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*ft_getvar_in_env(char *str, t_env *env, int error)
{
	while (env && ft_strccmp(str, env->var, '=') != 0)
		env = env->next;
	if (!env)
	{
		if (error == 1)
		{
			ft_putcstr_fd(str, 2, '=');
			ft_putstr_fd(" : is not set \n", 2);
		}
		return (NULL);
	}
	return (ft_strdup((env->var + (ft_strclen(env->var, '=') + 1))));
}

char		*ft_getpath(char **arg, int size, t_env *env)
{
	char	*path;

	if (size == 1)
	{
		if (!(path = ft_getvar_in_env("HOME=", env, 1)))
			path = (char*)ft_memalloc(1);
		return (path);
	}
	else if (size == 2 && arg[1][0] == '-' &&
		arg[1][1] == '\0')
	{
		if (!(path = ft_getvar_in_env("OLDPWD=", env, 1)))
			path = (char*)ft_memalloc(1);
		return (path);
	}
	return (ft_strdup(arg[1]));
}

char		*ft_getoldpwd(t_env *env)
{
	char	*to_ret;

	if (!(to_ret = getcwd(NULL, 1024)))
	{
		if (!(to_ret = ft_getvar_in_env("PWD=", env, 0)))
		{
			if (!(to_ret = ft_getvar_in_env("OLDPWD=", env, 0)))
				return ((char*)ft_memalloc(1));
		}
	}
	return (to_ret);
}
