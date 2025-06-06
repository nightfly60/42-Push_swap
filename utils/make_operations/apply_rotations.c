/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:47:47 by edurance          #+#    #+#             */
/*   Updated: 2025/06/06 13:21:53 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	apply_rest_rotations(int *tab, t_list **a, t_list **b)
{
	while (tab[0])
	{
		ra(a);
		tab[0]--;
	}
	while (tab[1])
	{
		rra(a);
		tab[1]--;
	}
	while (tab[2])
	{
		rb(b);
		tab[2]--;
	}
	while (tab[3])
	{
		rrb(b);
		tab[3]--;
	}
}

static void	apply_ope(int *tab, t_list **a, t_list **b)
{
	while (tab[0] && tab[2])
	{
		rr(a, b);
		tab[0]--;
		tab[2]--;
	}
	while (tab[1] && tab[3])
	{
		rrr(a, b);
		tab[1]--;
		tab[3]--;
	}
	apply_rest_rotations(tab, a, b);
}

/*pb with the min operations*/
void	apply_min(t_list **a, t_list **b)
{
	int	x;
	int	smaller;
	int	*res;
	int	min;

	x = 0;
	min = INT_MAX;
	while (x < ft_lstsize(*a))
	{
		res = operations(*a, *b, x, ((t_data *)ft_lstget(*a,
						x)->content)->rank);
		if (min > total_operations(res))
		{
			min = res[0] + res[1] + res[2] + res[3];
			smaller = x;
		}
		x++;
		free(res);
	}
	res = operations(*a, *b, smaller, ((t_data *)ft_lstget(*a,
					smaller)->content)->rank);
	total_operations(res);
	apply_ope(res, a, b);
	pb(a, b);
	free(res);
}
