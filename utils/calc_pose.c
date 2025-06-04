/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_pose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:50:56 by edurance          #+#    #+#             */
/*   Updated: 2025/06/04 18:17:54 by edurance         ###   ########.fr       */
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

int sum_operations(int *res)
{
	int total;
	int b_rotate;
	int a_rotate;

	total = 0;
	if (res[0] > res[1])
		a_rotate = res[1];
	else
		a_rotate = res[0];
	if (res[2] > res[3])
		b_rotate = res[3];
	else
		b_rotate = res[2];
	if ((b_rotate == res[2] && a_rotate == res[0]) || (b_rotate == res[3] && a_rotate == res[1]))
	{
		if (b_rotate > a_rotate)
			total = b_rotate;
		else
			total = a_rotate;
	}
	else
		total = b_rotate + a_rotate;
	return (total);
}
