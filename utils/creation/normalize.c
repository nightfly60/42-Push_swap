/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:49:26 by edurance          #+#    #+#             */
/*   Updated: 2025/06/07 14:45:11 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	find_min(t_list **stack)
{
	int		min;
	int		min_index;
	int		index;
	t_list	*temp_stack;

	temp_stack = *stack;
	index = 0;
	min_index = -1;
	min = 0;
	while (temp_stack)
	{
		if (((t_data *)temp_stack->content)->rank == -1)
		{
			if (min_index == -1 || ((t_data *)temp_stack->content)->value < min)
			{
				min = ((t_data *)temp_stack->content)->value;
				min_index = index;
			}
		}
		temp_stack = temp_stack->next;
		index++;
	}
	return (min_index);
}

/*(ranks)*/
void	ft_normalize(t_list **stack)
{
	int		num;
	int		size;
	t_list	*first;

	size = ft_lstsize(*stack);
	num = 0;
	while (num < size)
	{
		first = ft_lstget(*stack, find_min(stack));
		((t_data *)first->content)->rank = num;
		num++;
	}
}
