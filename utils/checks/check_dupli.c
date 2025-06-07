/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dupli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:49:09 by edurance          #+#    #+#             */
/*   Updated: 2025/06/07 14:45:02 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*check unique*/
int	check_dupli(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i <= ac)
	{
		j = 1;
		while (j <= ac)
		{
			if (!ft_strcmp(av[i], av[j]) && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
