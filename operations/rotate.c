/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:57:46 by edurance          #+#    #+#             */
/*   Updated: 2025/05/28 19:14:02 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Shift up all elements of stack a by 1*/
void	ft_ra(t_list **stack_a)
{
	ft_lstrotate(stack_a);
}

/*Shift up all elements of stack b by 1*/
void	ft_rb(t_list **stack_b)
{
	ft_lstrotate(stack_b);
}

/*ra and rb at the same time*/
void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}
