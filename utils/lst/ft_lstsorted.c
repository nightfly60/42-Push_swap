/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:53:37 by edurance          #+#    #+#             */
/*   Updated: 2025/06/07 16:11:16 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_lstsorted(t_list *stack, int prem)
{
	t_list	*n;
	int		first;
	int		content;
	int		next_content;

	if (!stack)
		return (1);
	first = ((t_data *)stack->content)->value;
	while (stack->next)
	{
		n = stack->next;
		next_content = ((t_data *)n->content)->value;
		content = ((t_data *)stack->content)->value;
		if (n && next_content < content)
		{
			if (prem && ft_lstsorted(n, 0)
				&& ((t_data *)ft_lstlast(n)->content)->value < first)
				return (1);
			else
				return (0);
		}
		stack = stack->next;
	}
	return (1);
}
