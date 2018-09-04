/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:29:13 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/23 16:37:26 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_printenv(t_env *env)
{
	while (env)
	{
		if (env->var[0] != ' ' && env->var[1] != '\0')
			ft_printf("%s\n", env->var);
		env = env->next;
	}
}
