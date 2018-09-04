/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:01:16 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/23 11:35:42 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_getpwd(char *path, t_env *env)
{
	char	*pwd;

	if (!(pwd = getcwd(NULL, 1024)))
	{
		if (!(pwd = ft_getvar_in_env("PWD=", env, 0)))
			if (!(pwd = (char*)ft_memalloc(1)))
				return (NULL);
		ft_putstr_fd("minishell : cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	return (pwd);
}

void		ft_free(char *str1, char *str2, char **tab)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	if (tab)
		ft_freetab(tab);
}

char		**ft_getallpwd(t_env *env, char *path)
{
	char	**to_ret;
	char	*old_pwd;
	char	*pwd;

	if (!(to_ret = (char**)malloc(sizeof(char*) * 3)))
		return (NULL);
	if (!(old_pwd = ft_getoldpwd(env)))
	{
		free(to_ret);
		return (NULL);
	}
	chdir(path);
	if (!(pwd = ft_getpwd(path, env)))
	{
		ft_free(old_pwd, NULL, to_ret);
		return (NULL);
	}
	if (!(to_ret[0] = ft_strjoin("OLDPWD=", old_pwd)) ||
			!(to_ret[1] = ft_strjoin("PWD=", pwd)))
	{
		ft_free(old_pwd, pwd, to_ret);
		return (NULL);
	}
	ft_free(old_pwd, pwd, NULL);
	return (to_ret);
}

int			ft_cd(char **arg, t_env *env)
{
	int		size;
	char	*path;
	char	**all_pwd;

	size = ft_lentab(arg);
	if (ft_check_arg_cd(size, arg) == 1)
		return (0);
	if (!(path = ft_getpath(arg, size, env)))
		return (-1);
	if ((ft_checkaccess(path)) == 1)
		return (0);
	if ((ft_check_is_dir(path)) == 1)
		return (0);
	if (!(all_pwd = ft_getallpwd(env, path)))
	{
		free(path);
		return (-1);
	}
	all_pwd[2] = 0;
	ft_setenv(env, all_pwd);
	free(path);
	ft_freetab(all_pwd);
	return (0);
}
