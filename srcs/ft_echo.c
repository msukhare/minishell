/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:22:51 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/22 13:34:37 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_echo(char **arg)
{
	int	i;
	int	bckshn;

	i = 1;
	bckshn = 1;
	if (ft_lentab(arg) <= 1)
	{
		ft_putchar('\n');
		return ;
	}
	if (arg[i][0] == '-' && arg[i][1] == 'n' && arg[i][2] == '\0')
	{
		bckshn = 0;
		i++;
	}
	while (arg[i])
	{
		ft_putstr(arg[i]);
		i++;
		if (arg[i])
			ft_putchar(' ');
	}
	(bckshn) ? ft_putchar('\n') : 0;
}
