/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:28:15 by edurance          #+#    #+#             */
/*   Updated: 2025/05/31 15:48:34 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Swap the first 2 elements*/
void	ft_lstswap(t_list **stack)
{
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->previous = temp;
	(*stack)->next = temp->next;
	temp->next = *stack;
	temp->previous = NULL;
	*stack = temp;
}

/*Shift up all elements by 1*/
void	ft_lstrotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	(*stack)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
}

/*Shift down all elements by 1*/
void	ft_lstrev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack)
		return ;
	last = ft_lstlast(*stack);
	tmp = last;
	last = last->previous;
	last->next = NULL;
	tmp->previous = NULL;
	ft_lstadd_front(stack, tmp);
}

int	ft_lstsorted(t_list *stack, int prem)
{
	t_list	*n;
	int		first;
	int		content;
	int		next_content;

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

int	ft_lstmin(t_list **stack)
{
	int		min;
	int		min_index;
	int		index;
	t_list	*temp_stack;

	temp_stack = *stack;
	index = 0;
	min_index = -1;
	min = 0;
	while (temp_stack)
	{
		if (((t_data *)temp_stack->content)->rank == -1)
		{
			if (min_index == -1 || ((t_data *)temp_stack->content)->value < min)
			{
				min = ((t_data *)temp_stack->content)->value;
				min_index = index;
			}
		}
		temp_stack = temp_stack->next;
		index++;
	}
	return (min_index);
}

int	ft_lstmax(t_list **stack)
{
	int		max;
	int		count;
	t_list	*temp_stack;

	temp_stack = *stack;
	max = ((t_data *)temp_stack->content)->value;
	count = 0;
	while (temp_stack)
	{
		temp_stack = temp_stack->next;
		if (temp_stack && max < ((t_data *)temp_stack->content)->value)
		{
			max = ((t_data *)temp_stack->content)->value;
			count++;
		}
	}
	return (count);
}

void	printlist(void *content)
{
	printf("%d\n", *(int *)content);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*btemp;
	int		temp;
	int		operations;
	int		count;
	int		k;

	ac = ac - 1;
	a = NULL;
	b = NULL;
	operations = 0;
	if (!ac)
		return (0);
	if (!check_int(av) || !check_dupli(ac, av))
		return (write(2, "Error\n", 6));
	create_list(&a, ac, av);
	ft_normalize(&a);
	ft_push_five(&a, &b, 5, 0);
	printf("LIST B\n");
	ft_lstiter(b, &printlist);
	printf("COMPTEUR : %d\n", operations);
	ft_lstclear(&a, &free);
	ft_lstclear(&b, &free);
	return (0);
}
