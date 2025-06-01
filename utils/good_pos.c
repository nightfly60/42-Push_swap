/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:50:56 by edurance          #+#    #+#             */
/*   Updated: 2025/06/01 18:03:46 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	printlist(void *content)
{
	t_data	*data;

	data = ((t_data *)content);
	printf("valeur : %d | rank : %d\n", data->value, data->rank);
}

static int	ft_lstmax(t_list **stack, int value)
{
	int		max;
	int		i;
	t_list	*temp_stack;

	int res = 1; // <-- initialise à 0
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
			printf("old max = %d new max = %d\n", max, ((t_data *)temp_stack->content)->rank);
			max = ((t_data *)temp_stack->content)->rank;
			res = i;
		}
	}
	if (max < value)
		return (res);
	return (-1);
}

static int	ft_lstmin(t_list **stack, int value)
{
	int		min;
	int		i;
	t_list	*temp_stack;

	int res = 0; // <-- initialise à 0
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
			res = i;
		}
		i++;
	}
	if (value < min)
		return (res);
	return (-1);
}

int	good_pos(t_list *stack_b, int index)
{
	t_data	*data;
	t_data	*next_data;
	t_list	*temp;
	int		res;

	temp = stack_b;
	res = 0;
	if (!temp)
		return (0);
	if (ft_lstmin(&stack_b, index) != -1)
		return (ft_lstmin(&stack_b, index) + 1);
	if (ft_lstmax(&stack_b, index) != -1)
		return (ft_lstmax(&stack_b, index));
	while (temp && temp->next)
	{
		data = ((t_data *)temp->content);
		next_data = ((t_data *)temp->next->content);
		printf("index = %d, data = %d next data = %d\n", index, data->rank, next_data->rank);
		// if (index > data->rank && index < next_data->rank)
		if (index < data->rank && index > next_data->rank)
		{
			printf("here ret= %d\n", res);
			return (res+1);
		}
		res++;
		temp = temp->next;
	}
	return (0);
}
