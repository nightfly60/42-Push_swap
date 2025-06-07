/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:21:39 by edurance          #+#    #+#             */
/*   Updated: 2025/06/07 20:30:52 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Shift down all elements of stack a by 1*/
void	rra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	last = ft_lstlast(*stack_a);
	temp = last->previous;
	last->next = *stack_a;
	if (temp)
		temp->next = NULL;
	last->previous = NULL;
	(*stack_a)->previous = last;
	*stack_a = last;
	write(1, "rra\n", 4);
}

/*Shift down all elements of stack b by 1*/
void	rrb(t_list **stack_b)
{
	ft_lstrev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

/*rra and rrb at the same time*/
void	rrr(t_list **stack_a, t_list **stack_b)
{
	ft_lstrev_rotate(stack_a);
	ft_lstrev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
