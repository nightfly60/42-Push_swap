/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:46:41 by edurance          #+#    #+#             */
/*   Updated: 2025/06/06 22:37:49 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Swap the first 2 elements at the top of stack a*/
void	sa(t_list **stack_a)
{
	ft_lstswap(stack_a);
	write(1, "sa\n", 3);
}

/*Swap the first 2 elements at the top of stack b*/
void	sb(t_list **stack_b)
{
	ft_lstswap(stack_b);
	write(1, "sb\n", 3);
}

/*sa and sb at the same time*/
void	ss(t_list **stack_a, t_list **stack_b)
{
	ft_lstswap(stack_a);
	ft_lstswap(stack_b);
	write(1, "ss\n", 3);
}
