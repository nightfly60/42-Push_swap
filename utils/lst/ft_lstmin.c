/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:41:27 by edurance          #+#    #+#             */
/*   Updated: 2025/06/06 12:41:45 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_lstmin(t_list **stack)
{
	int		min;
	int		i;
	t_list	*temp_stack;
	int		res;

	res = 0;
	temp_stack = *stack;
	i = 0;
	if (temp_stack)
		min = ((t_data *)temp_stack->content)->rank;
	while (temp_stack)
	{
		temp_stack = temp_stack->next;
		if (temp_stack && min > ((t_data *)temp_stack->content)->rank)
		{
			min = ((t_data *)temp_stack->content)->rank;
			res = i + 1;
		}
		i++;
	}
	return (res);
}
