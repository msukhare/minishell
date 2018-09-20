/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:22:44 by msukhare          #+#    #+#             */
/*   Updated: 2018/09/20 16:40:30 by kemar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_sig;

void			ft_catchsig(int sig)
{
	(void)sig;
	ft_putstr("\n");
	if (g_sig == 0)
		ft_putloca(NULL, NULL);
}

static void		ft_push_to_exe(t_cmd **begin_list, t_env **begin_env, char *c)
{
	g_sig = 1;
	ft_execcmd(begin_list, begin_env);
	ft_putloca(begin_env, begin_list);
	g_sig = 0;
	*c = '\0';
}

static int		ft_buffgood(char buff)
{
	if ((buff >= 32 && buff <= 126) || buff == '\t' || buff == '\a' ||
			buff == '\b')
		return (1);
	return (0);
}

static void		ft_readcmd(t_env **beg_env)
{
	char		buff;
	t_cmd		*bg_lst;
	t_cmd		*tmp;
	int			rt_rd;

	bg_lst = NULL;
	while ((rt_rd = read(0, &buff, 1)) >= 0)
	{
		(rt_rd == 0 && !bg_lst) ? ft_exit_read(beg_env, 1, &bg_lst) : 0;
		if (!bg_lst && ft_buffgood(buff) && buff != '\n')
		{
			(!(bg_lst = ft_creatlist(buff, NULL))) ? exit(1) : 0;
			tmp = bg_lst;
		}
		else if (buff != '\n' && ft_buffgood(buff) && bg_lst)
		{
			if (!(tmp->next = ft_creatlist(buff, tmp)))
				ft_exit_read(beg_env, 0, &bg_lst);
			tmp = tmp->next;
		}
		(buff == '\n' && bg_lst) ? ft_push_to_exe(&bg_lst, beg_env, &buff) : 0;
		(buff == '\n') ? ft_putloca(beg_env, &bg_lst) : 0;
		buff = '\0';
	}
}

int				main(void)
{
	extern char **environ;
	t_env		*begin_env;

	g_sig = 0;
	signal(SIGINT, ft_catchsig);
	if (environ[0] && !(begin_env = ft_createnv(environ)))
		exit(1);
	else if (!environ[0] && !(begin_env = ft_generatenv()))
		exit(1);
	ft_putloca(&begin_env, NULL);
	ft_readcmd(&begin_env);
	return (0);
}
