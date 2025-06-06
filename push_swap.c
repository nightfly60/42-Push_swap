/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:46:46 by edurance          #+#    #+#             */
/*   Updated: 2025/06/06 22:48:30 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_back(t_list **a, t_list **b)
{
	int	actual;

	while (*b)
	{
		actual = (((t_data *)ft_lstlast(*a)->content)->rank);
		if (actual == ((((t_data *)(*a)->content)->rank) - 1))
			rra(a);
		else
			pa(a, b);
	}
	if (ft_lstmin(a) > ft_lstsize(*a) / 2)
	{
		while (ft_lstmin(a))
			rra(a);
	}
	else
	{
		while (ft_lstmin(a))
			ra(a);
	}
}

void	push_swap(t_list **a, t_list **b)
{
	int	max_pos;

	pb(a, b);
	pb(a, b);
	while (*a && ft_lstsize(*a) > 3)
		apply_min(a, b);
	sort_three(a);
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
	push_back(a, b);
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
	if (ft_lstsorted(a, 1))
	{
		if (ft_lstmin(&a) > ft_lstsize(a) / 2)
		{
			while (ft_lstmin(&a))
				rra(&a);
		}
		else
		{
			while (ft_lstmin(&a))
				ra(&a);
		}
	}
	else if (ft_lstsize(a) == 3)
		sort_three(&a);
	else
		push_swap(&a, &b);
	ft_lstclear(&a, &free);
	return (0);
}
