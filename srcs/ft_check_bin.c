/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:59:18 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/23 11:29:26 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env			*ft_check_path(t_env *env)
{
	t_env		*tmp;

	tmp = env;
	while (tmp && (ft_strccmp(tmp->var, "PATH=", '=') != 0))
		tmp = tmp->next;
	if (!tmp)
	{
		ft_putstr_fd("minish: PATH is not set\n", 2);
		return (NULL);
	}
	return (tmp);
}

int				ft_checkbin(char *path_cmd, char *cmd)
{
	t_stat		buff;

	if ((lstat(path_cmd, &buff)) < 0)
		return (-1);
	if ((S_ISREG(buff.st_mode)) == 0)
	{
		ft_putstr(path_cmd);
		ft_putstr(": is not an executable\n");
		(path_cmd != cmd) ? free(path_cmd) : 0;
		return (-1);
	}
	if ((access(path_cmd, R_OK | X_OK)) == -1)
	{
		ft_putstr("Permission denied\n");
		(path_cmd != cmd) ? free(path_cmd) : 0;
		return (-1);
	}
	return (1);
}
