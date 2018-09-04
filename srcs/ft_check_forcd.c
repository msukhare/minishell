/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_forcd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 10:54:14 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/24 13:31:33 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_check_arg_cd(int size, char **arg)
{
	if (size == 3)
	{
		ft_putstr_fd("cd:", 2);
		ft_putstr_fd(": string not in pwd:", 2);
		ft_putstr_fd(arg[2], 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	else if (size > 3)
	{
		ft_putstr_fd("cd:", 2);
		ft_putstr_fd("too many arguments\n", 2);
		return (1);
	}
	return (0);
}

int			ft_checkaccess(char *path)
{
	if (path[0] == '\0')
	{
		free(path);
		return (1);
	}
	else if ((access(path, F_OK)) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		free(path);
		return (1);
	}
	else if ((access(path, R_OK | X_OK)) == -1)
	{
		ft_putstr_fd("cd:", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		free(path);
		return (1);
	}
	return (0);
}

int			ft_check_is_dir(char *path)
{
	t_stat	stat;

	if ((lstat(path, &stat)) == -1)
		return (0);
	if (S_ISDIR(stat.st_mode) != 1)
	{
		ft_putstr_fd("cd: not a directory: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		free(path);
		return (1);
	}
	return (0);
}
