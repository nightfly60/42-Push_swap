/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_pose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:50:56 by edurance          #+#    #+#             */
/*   Updated: 2025/06/05 13:19:36 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	printlist(void *content)
{
	t_data	*data;

	data = ((t_data *)content);
	printf("valeur : %d | rank : %d\n", data->value, data->rank);
}

static int	ft_lstmax(t_list **stack)
{
	int		max;
	int		i;
	t_list	*temp_stack;
	int		res;

	res = 0;
	temp_stack = *stack;
	i = 0;
	if (temp_stack)
		max = ((t_data *)temp_stack->content)->rank;
	while (temp_stack)
	{
		i++;
		temp_stack = temp_stack->next;
		if (temp_stack && max < ((t_data *)temp_stack->content)->rank)
		{
			max = ((t_data *)temp_stack->content)->rank;
			res = i;
		}
	}
	return (res);
}

static int	ft_lstmin(t_list **stack)
{
	int		min;
	int		i;
	t_list	*temp_stack;
	int		res;

	res = 0;
	temp_stack = *stack;
	i = 0;
	if (temp_stack)
		min = ((t_data *)temp_stack->content)->rank;
	while (temp_stack)
	{
		temp_stack = temp_stack->next;
		if (temp_stack && min > ((t_data *)temp_stack->content)->rank)
		{
			min = ((t_data *)temp_stack->content)->rank;
			res = i + 1;
		}
		i++;
	}
	return (res);
}

int	b_rotations(t_list **b, int rank)
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

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	*operations(t_list *a, t_list *b, int x, int rank)
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

int	total_operations(int *tab)
{
	int	min;

	min = ft_min(tab[0], tab[1]) + ft_min(tab[2], tab[3]);
	if (min > ft_max(tab[0], tab[2]))
		min = ft_max(tab[0], tab[2]);
	if (min > ft_max(tab[1], tab[3]))
		min = ft_max(tab[1], tab[3]);
	if (min == ft_min(tab[0], tab[1]) + ft_min(tab[2], tab[3]))
	{
		if (tab[0] == ft_max(tab[0], tab[1]))
			tab[0] = 0;
		else
			tab[1] = 0;
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

void	apply_ope(int *tab, t_list **a, t_list **b)
{
	int	i;

	i = 0;
	while (tab[0] && tab[2])
	{
		ft_rr(a, b);
		tab[0]--;
		tab[2]--;
	}
	while (i < 4)
	{
		while (tab[i])
		{
			if (i == 0)
				ft_ra(a);
			else if (i == 1)
				ft_rra(a);
			else if (i == 2)
				ft_rb(b);
			else if (i == 3)
				ft_rrb(b);
			tab[i]--;
		}
		i++;
	}
}
