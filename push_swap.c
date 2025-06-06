/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:46:46 by edurance          #+#    #+#             */
/*   Updated: 2025/06/06 13:22:49 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **a, t_list **b)
{
	int	max_pos;

	pb(a, b);
	pb(a, b);
	while (*a)
		apply_min(a, b);
	max_pos = ft_lstmax(b);
	if (max_pos > ft_lstsize(*b) / 2)
	{
		while (ft_lstmax(b))
			rrb(b);
	}
	else
	{
		while (ft_lstmax(b))
			rb(b);
	}
	while (*b)
		pa(a, b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		*res;
	int		max_pos;

	ac = ac - 1;
	a = NULL;
	b = NULL;
	if (!ac)
		return (0);
	if (!check_int(av) || !check_dupli(ac, av))
		return (write(2, "Error\n", 6));
	create_list(&a, ac, av);
	ft_normalize(&a);
	push_swap(&a, &b);
	ft_lstclear(&a, &free);
	return (0);
}
