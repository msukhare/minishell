/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managecmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:38:22 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/23 13:23:07 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_checkcoma(t_cmd **bg_lst)
{
	t_cmd	*tmp;
	int		find;

	tmp = *bg_lst;
	find = 0;
	if ((*bg_lst)->cara == ';')
		return (ft_puterror(bg_lst));
	while (tmp)
	{
		if (tmp->cara == ';' && find == 0)
			find = 1;
		else if (tmp->cara == ';' && find == 1)
			return (ft_puterror(bg_lst));
		else if (tmp->cara != ';')
			find = 0;
		tmp = tmp->next;
	}
	return (0);
}

static void	ft_exec_whit_file(char *cmd, char **arg, t_env **env, t_cmd **bg_l)
{
	int		error;

	error = 0;
	if (ft_strcmp(cmd, "echo") == 0)
		ft_echo(arg);
	else if (ft_strcmp(cmd, "cd") == 0)
		error = ft_cd(arg, *env);
	else if (ft_strcmp(cmd, "setenv") == 0)
		error = ft_setenv(*env, arg);
	else if (ft_strcmp(cmd, "unsetenv") == 0)
		ft_unsetenv(arg, env);
	else if (ft_strcmp(cmd, "env") == 0)
		error = ft_env(*env, arg);
	else if (ft_strcmp(cmd, "exit") == 0)
		ft_exitshell(cmd, arg, env, bg_l);
	else
		error = ft_execbin(cmd, *env, arg);
	if (error == -1)
	{
		free(cmd);
		ft_freetab(arg);
		ft_dellist(bg_l);
		ft_dellst(*env);
		exit(1);
	}
}

void		ft_execcmd(t_cmd **bg_list, t_env **begin_env)
{
	char	*cmd;
	char	**arg_cmd;
	t_cmd	*tmp;

	if (ft_checkcoma(bg_list) == -1)
		return ;
	if (!(cmd = ft_getcmd(bg_list)) ||
			!(arg_cmd = ft_getarg(bg_list)))
	{
		(cmd) ? free(cmd) : 0;
		ft_dellist(bg_list);
		ft_dellst(*begin_env);
		exit(1);
	}
	(cmd[0] != '\0') ? ft_exec_whit_file(cmd, arg_cmd, begin_env, bg_list) : 0;
	ft_freetab(arg_cmd);
	free(cmd);
	if (*bg_list && (*bg_list)->cara == ';')
	{
		tmp = *bg_list;
		*bg_list = (*bg_list)->next;
		free(tmp);
		(*bg_list) ? ft_execcmd(bg_list, begin_env) : 0;
	}
	ft_dellist(bg_list);
}
