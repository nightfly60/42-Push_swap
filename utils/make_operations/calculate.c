/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:44:25 by edurance          #+#    #+#             */
/*   Updated: 2025/06/06 13:15:20 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	b_rotations(t_list **b, int rank)
{
	t_list	*temp;
	int		position;
	t_data	*data;
	t_data	*next_data;

	temp = *b;
	position = 0;
	if (rank < (((t_data *)ft_lstget(temp, ft_lstmin(b))->content)->rank))
		return (ft_lstmax(b));
	if (rank > (((t_data *)ft_lstget(temp, ft_lstmax(b))->content)->rank))
		return (ft_lstmax(b));
	while (temp && temp->next)
	{
		data = ((t_data *)temp->content);
		next_data = ((t_data *)temp->next->content);
		if (data->rank > rank && next_data->rank < rank)
			return (position + 1);
		temp = temp->next;
		position++;
	}
	return (0);
}

/*[ra, rra, rb, rrb]*/
static int	*operations(t_list *a, t_list *b, int x, int rank)
{
	int	*res;

	res = malloc(sizeof(int) * 4);
	if (!res)
		return (NULL);
	res[0] = x;
	res[1] = ft_lstsize(a) - x;
	res[2] = b_rotations(&b, rank);
	res[3] = ft_lstsize(b) - res[2];
	return (res);
}

static int	min_operations(int *tab)
{
	int	min;

	min = ft_min(tab[0], tab[1]) + ft_min(tab[2], tab[3]);
	if (min > ft_max(tab[0], tab[2]))
		min = ft_max(tab[0], tab[2]);
	if (min > ft_max(tab[1], tab[3]))
		min = ft_max(tab[1], tab[3]);
	return (min);
}

int	total_operations(int *tab)
{
	int	min;

	min = min_operations(tab);
	if (min == ft_min(tab[0], tab[1]) + ft_min(tab[2], tab[3]))
	{
		if (tab[0] == ft_max(tab[0], tab[1]))
			tab[0] = 0;
		else
			tab[1] = 0;
		if (tab[2] == ft_max(tab[2], tab[3]))
			tab[2] = 0;
		else
			tab[3] = 0;
	}
	else if (min == ft_max(tab[0], tab[2]))
	{
		tab[1] = 0;
		tab[3] = 0;
	}
	else if (min == ft_max(tab[1], tab[3]))
	{
		tab[0] = 0;
		tab[2] = 0;
	}
	return (min);
}
