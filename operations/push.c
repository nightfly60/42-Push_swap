/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:08:30 by edurance          #+#    #+#             */
/*   Updated: 2025/05/28 18:17:53 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Take the first element at the top of b and put it at the top of a*/
void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b)
		return ;
	ft_lstadd_front(stack_a, stack_b);
}

/*Take the first element at the top of a and put it at the top of b*/
void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a)
		return ;
	ft_lstadd_front(stack_b, stack_a);
}
