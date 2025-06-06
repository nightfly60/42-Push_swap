/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:28:15 by edurance          #+#    #+#             */
/*   Updated: 2025/06/06 12:55:20 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*Swap the first 2 elements*/
void	ft_lstswap(t_list **stack)
{
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->previous = temp;
	(*stack)->next = temp->next;
	temp->next = *stack;
	temp->previous = NULL;
	*stack = temp;
}

/*Shift up all elements by 1*/
void	ft_lstrotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	(*stack)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
}

/*Shift down all elements by 1*/
void	ft_lstrev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack)
		return ;
	last = ft_lstlast(*stack);
	tmp = last;
	last = last->previous;
	last->next = NULL;
	tmp->previous = NULL;
	ft_lstadd_front(stack, tmp);
}
