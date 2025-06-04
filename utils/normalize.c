/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:49:26 by edurance          #+#    #+#             */
/*   Updated: 2025/06/04 15:35:42 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstget(t_list *stack, int place)
{
	int	i;

	i = 0;
	while (stack && i < place)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

static int	ft_lstmin(t_list **stack)
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

void	ft_normalize(t_list **stack)
{
	int		num;
	int		size;
	t_list	*first;

	size = ft_lstsize(*stack);
	num = 0;
	while (num < size)
	{
		first = ft_lstget(*stack, ft_lstmin(stack));
		((t_data *)first->content)->rank = num;
		num++;
	}
}
