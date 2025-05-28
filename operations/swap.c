/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:46:41 by edurance          #+#    #+#             */
/*   Updated: 2025/05/28 14:01:45 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


/*Swap the first 2 elements at the top of stack a*/
void	sa(int **stack_a)
{
	int	temp;

	temp = 0;
	if (!(*stack_a)[0] || !(*stack_a)[1])
		return ;
	temp = (*stack_a)[0];
	(*stack_a)[0] = (*stack_a)[1];
	(*stack_a)[1] = temp;
}

/*Swap the first 2 elements at the top of stack b*/

