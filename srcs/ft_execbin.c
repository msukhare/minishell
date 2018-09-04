/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execbin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:11:46 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/23 15:21:06 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*ft_creatnewpaths(char *old_paths, int size)
{
	char		*new_paths;
	int			i;

	if (!(new_paths = (char*)malloc(sizeof(char) * (size + 2))))
		return (NULL);
	i = 0;
	while (old_paths[i])
	{
		new_paths[i] = old_paths[i];
		i++;
	}
	new_paths[i++] = '/';
	new_paths[i] = '\0';
	free(old_paths);
	return (new_paths);
}

static int		ft_addslash(char **paths)
{
	int			i;
	int			j;
	char		*tmp;

	i = 0;
	while (paths[i])
	{
		j = 0;
		while (paths[i][j])
			j++;
		if (j >= 1 && paths[i][j - 1] != '/')
		{
			if (!(tmp = ft_creatnewpaths(paths[i], j)))
			{
				ft_freetab(paths);
				return (-1);
			}
			paths[i] = tmp;
		}
		i++;
	}
	return (0);
}

static char		*ft_creatpath(char *cmd, t_env *pathlst)
{
	char		*to_ret;
	char		**paths;
	int			i;

	if (!(paths = ft_strsplit((pathlst->var + 5), ':')) ||
			(ft_addslash(paths)) == -1)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		to_ret = cmd;
		if ((ft_strncmp(paths[i], cmd, ft_strlen(paths[i]))) != 0 &&
				!(to_ret = ft_strjoin(paths[i], cmd)))
			return (NULL);
		if (access(to_ret, F_OK) != -1)
		{
			ft_freetab(paths);
			return (to_ret);
		}
		(to_ret != cmd) ? free(to_ret) : 0;
		i++;
	}
	ft_print_error(cmd);
	ft_freetab(paths);
	return (NULL);
}

static char		**ft_creat_tabenv(t_env *env)
{
	char		**tab;
	int			i;

	if (!(tab = (char **)malloc(sizeof(char *) * (ft_lstlen(env) + 1))))
		return (NULL);
	i = 0;
	while (env)
	{
		if (!(tab[i] = ft_strdup(env->var)))
		{
			ft_freetab(tab);
			return (NULL);
		}
		i++;
		env = env->next;
	}
	tab[i] = 0;
	return (tab);
}

int				ft_execbin(char *cmd, t_env *env, char **arg)
{
	char		**env_in_tab;
	char		*path_cmd;
	t_env		*pathlst;
	pid_t		son;

	if (access(cmd, F_OK) != -1)
		path_cmd = cmd;
	else if ((pathlst = ft_check_path(env)))
	{
		if (!(path_cmd = ft_creatpath(cmd, pathlst)))
			return (0);
	}
	else
		return (0);
	if (ft_checkbin(path_cmd, cmd) != 1)
		return (0);
	if (!(env_in_tab = ft_creat_tabenv(env)))
		return (-1);
	son = fork();
	(son > 0) ? wait(0) : 0;
	if (son == 0)
		(execve(path_cmd, arg, env_in_tab) == -1) ? exit(1) : 0;
	(path_cmd != cmd) ? free(path_cmd) : 0;
	ft_freetab(env_in_tab);
	return (0);
}
