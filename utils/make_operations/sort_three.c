/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:32:25 by edurance          #+#    #+#             */
/*   Updated: 2025/06/06 21:29:37 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_three(t_list **a)
{
	t_data	*current;
	t_data	*next;

	while (!ft_lstsorted(*a, 1))
	{
		current = ((t_data *)((*a)->content));
		next = ((t_data *)((*a)->next->content));
		if (current->rank > next->rank)
			sa(a);
		else
			ra(a);
	}
	while (ft_lstmin(a))
		ra(a);
}
