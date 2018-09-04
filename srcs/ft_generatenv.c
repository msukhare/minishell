/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generatenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:57:57 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/22 14:42:22 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*ft_getdefault_pwd(void)
{
	char	*to_ret;

	if (!(to_ret = getcwd(NULL, 1024)))
	{
		if (!(to_ret = ft_strdup("/")))
			return (NULL);
		chdir(to_ret);
	}
	return (to_ret);
}

t_env		*ft_generatenv(void)
{
	char	*pwd;
	char	**env;
	t_env	*begin_list;

	if (!(pwd = ft_getdefault_pwd()))
		return (NULL);
	if (!(env = (char**)malloc(sizeof(char *) * 4)))
	{
		free(pwd);
		return (NULL);
	}
	env[0] = ft_strjoin("PWD=", pwd);
	env[1] = ft_strjoin("OLDPWD=", pwd);
	env[2] = ft_strjoin("HOME=", "/");
	if (!env[0] || !env[1] || !env[2])
	{
		ft_freetab(env);
		return (NULL);
	}
	env[3] = 0;
	begin_list = ft_createnv(env);
	free(pwd);
	ft_freetab(env);
	return (begin_list);
}
