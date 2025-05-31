/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:42:26 by edurance          #+#    #+#             */
/*   Updated: 2025/05/31 15:53:55 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_five(t_list **stack_a, t_list **stack_b, int maxrank,
		int minrank)
{
	int	rank;
	int	count;
	int	size;
	int	i;

	size = ft_lstsize(*stack_a);
	i = 0;
	count = 0;
	while (count < 5 && i < size)
	{
		rank = ((t_data *)(*stack_a)->content)->rank;
		if (rank <= maxrank && rank > minrank)
		{
			ft_pb(stack_a, stack_b);
			count++;
		}
		else
			ft_ra(stack_a);
		i++;
	}
}
