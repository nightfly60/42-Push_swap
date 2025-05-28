/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:53:39 by edurance          #+#    #+#             */
/*   Updated: 2025/05/28 13:25:00 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	convert_nbr(int ac, char **av, int **stack_a, int **stack_b)
{
	int		i;
	long	res;

	i = 0;
	*stack_a = malloc(sizeof(int) * ac);
	*stack_b = malloc(sizeof(int) * ac);
	if (!*stack_a || !*stack_b)
	{
		free(stack_a);
		free(stack_b);
		return (0);
	}
	while (i < ac)
	{
		res = ft_atoi(av[i + 1]);
		if (res < INT_MIN || res > INT_MAX)
		{
			free(stack_a);
			free(stack_b);
			return (0);
		}
		(*stack_a)[i] = (int)res;
		i++;
	}
	return (1);
}
