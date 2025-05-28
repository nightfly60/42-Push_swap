/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:21:39 by edurance          #+#    #+#             */
/*   Updated: 2025/05/28 19:48:49 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Shift down all elements of stack a by 1*/
void	ft_rra(t_list **stack_a)
{
	ft_lstrev_rotate(stack_a);
}

/*Shift down all elements of stack b by 1*/
void	ft_rrb(t_list **stack_b)
{
	ft_lstrev_rotate(stack_b);
}

/*rra and rrb at the same time*/
void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}
