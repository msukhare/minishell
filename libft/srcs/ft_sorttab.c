/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorttab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:28:58 by msukhare          #+#    #+#             */
/*   Updated: 2017/11/12 17:37:59 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		ft_sorttab(int *tab, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	min;
	int		temp;

	i = 0;
	while (i < len)
	{
		j = i;
		min = i;
		while (j < len)
		{
			if (tab[j] < tab[min])
				min = j;
			j++;
		}
		temp = tab[min];
		tab[min] = tab[i];
		tab[i] = temp;
		i++;
	}
}
