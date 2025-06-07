/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:42:12 by edurance          #+#    #+#             */
/*   Updated: 2025/06/07 14:45:16 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_lstmax(t_list **stack)
{
	int		max;
	int		i;
	t_list	*temp_stack;
	int		res;

	res = 0;
	temp_stack = *stack;
	i = 0;
	if (temp_stack)
		max = ((t_data *)temp_stack->content)->rank;
	while (temp_stack)
	{
		i++;
		temp_stack = temp_stack->next;
		if (temp_stack && max < ((t_data *)temp_stack->content)->rank)
		{
			max = ((t_data *)temp_stack->content)->rank;
			res = i;
		}
	}
	return (res);
}
