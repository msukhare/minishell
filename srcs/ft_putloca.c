/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putloca.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 10:47:07 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/22 10:49:17 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_putloca(t_env **begin_env, t_cmd **begin_list)
{
	char	*pwd;

	if (!(pwd = getcwd(NULL, 1024)))
	{
		if (!(pwd = ft_memalloc(1)))
		{
			(begin_env) ? ft_dellst(*begin_env) : 0;
			(begin_list) ? ft_dellist(begin_list) : 0;
			exit(1);
		}
	}
	ft_printf("[%s]:?>", pwd);
	free(pwd);
}
