/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:21:39 by edurance          #+#    #+#             */
/*   Updated: 2025/06/07 14:44:20 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Shift down all elements of stack a by 1*/
void	rra(t_list **stack_a)
{
	ft_lstrev_rotate(stack_a);
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
