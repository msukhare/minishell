/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:59:15 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/24 11:12:51 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit_read(t_env **begin_env, int ex, t_cmd **begin_list)
{
	if (ex == 1)
	{
		ft_putstr("\n");
		ft_putstr("exit\n");
	}
	if (begin_list)
		ft_dellist(begin_list);
	ft_dellst(*begin_env);
	exit(1);
}

void	ft_print_error(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	if (cmd[0] == '/')
		ft_putstr_fd(": No such file or directory\n", 2);
	else
		ft_putstr_fd(": commande not found\n", 2);
}

void	ft_exitshell(char *cmd, char **arg, t_env **env, t_cmd **bg_l)
{
	if (cmd)
		free(cmd);
	if (arg)
		ft_freetab(arg);
	if (env)
		ft_dellst(*env);
	if (bg_l)
		ft_dellist(bg_l);
	ft_putstr("exit\n");
	exit(1);
}

int		ft_puterror(t_cmd **bg_lst)
{
	ft_putstr_fd("minishell: syntax error near unexpected token ';;'\n", 2);
	ft_dellist(bg_lst);
	return (-1);
}
