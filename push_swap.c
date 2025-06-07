/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:46:46 by edurance          #+#    #+#             */
/*   Updated: 2025/06/07 20:41:07 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ret_sorted(t_list **a)
{
	if (ft_lstmin(a) > ft_lstsize(*a) / 2)
	{
		while (ft_lstmin(a))
		{
			rra(a);
		}
	}
	else
	{
		while (ft_lstmin(a))
		{
			ra(a);
		}
	}
}

static void	push_back(t_list **a, t_list **b)
{
	int	i;

	i = 0;
	if (ft_lstsize(*a) == 3)
		ft_lstlast(*a)->previous = (*a)->next;
	while (*b && i < 3)
	{
		if (*b && (((t_data *)(ft_lstlast(*a))->content)->rank) >
			((((t_data *)(*b)->content)->rank)))
		{
			i++;
			rra(a);
		}
		else
			pa(a, b);
	}
	while (*b)
		pa(a, b);
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
	ret_sorted(a);
}

static void	sort_args(t_list **a, t_list **b, int args, char **av)
{
	create_list(a, args, av);
	ft_normalize(a);
	if (ft_lstsorted(*a, 1))
		ret_sorted(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else
		push_swap(a, b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		args;

	args = ac - 1;
	a = NULL;
	b = NULL;
	if (!args)
		return (0);
	check_args(&av, &args);
	if (!check_int(av) || !check_dupli(args, av))
	{
		if (ac == 2)
			ft_freeall(av);
		write(2, "Error\n", 6);
		return (0);
	}
	sort_args(&a, &b, args, av);
	ft_lstclear(&a, &free);
	if (ac == 2)
		ft_freeall(av);
	return (0);
}
