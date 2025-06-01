/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:42:26 by edurance          #+#    #+#             */
/*   Updated: 2025/06/01 17:58:06 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	printlist(void *content)
{
	t_data	*data;

	data = ((t_data *)content);
	printf("valeur : %d | rank : %d\n", data->value, data->rank);
}


void	ft_push_five(t_list **stack_a, t_list **stack_b, int maxrank,
		int minrank)
{
	int	rank;
	int	count;
	int	size;
	int	i;
	int	pos;

	size = ft_lstsize(*stack_a);
	i = 0;
	count = 0;
	while (*stack_a && count < 5 && i < size)
	{
		rank = ((t_data *)(*stack_a)->content)->rank;
		if (rank < maxrank && rank >= minrank)
		{
				printf("##########################LIST B\n");
				ft_lstiter(*stack_b, &printlist);
				printf("le rank %d va en %d \n", rank, good_pos(*stack_b, rank));
				printf("##########################\n");
			pos = good_pos(*stack_b, rank);
			while (pos)
			{
				ft_rb(stack_b);
				pos--;
			}
			ft_pb(stack_a, stack_b);
		}
		else
			ft_ra(stack_a);
		i++;
	}
}
