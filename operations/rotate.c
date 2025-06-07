/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:57:46 by edurance          #+#    #+#             */
/*   Updated: 2025/06/07 14:44:22 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Shift up all elements of stack a by 1*/
void	ra(t_list **stack_a)
{
	ft_lstrotate(stack_a);
	write(1, "ra\n", 3);
}

/*Shift up all elements of stack b by 1*/
void	rb(t_list **stack_b)
{
	ft_lstrotate(stack_b);
	write(1, "rb\n", 3);
}

/*ra and rb at the same time*/
void	rr(t_list **stack_a, t_list **stack_b)
{
	ft_lstrotate(stack_a);
	ft_lstrotate(stack_b);
	write(1, "rr\n", 3);
}
