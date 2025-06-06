/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:40:28 by edurance          #+#    #+#             */
/*   Updated: 2025/06/06 13:18:30 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	check_digits(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-')
		i++;
	if (!av[i])
		return (0);
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_int(char **av)
{
	int		i;
	long	nbr;

	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) > 11 || !check_digits(av[i]))
			return (0);
		nbr = ft_atoi(av[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}
