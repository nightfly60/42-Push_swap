/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:49:26 by edurance          #+#    #+#             */
/*   Updated: 2025/05/30 18:40:22 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	printlist(void *content)
{
	printf("VALEUR : %d  |  RANK : %d\n", ((t_data *)content)->value,
		((t_data *)content)->rank);
}

t_list	*ft_lstget(t_list *stack, int place)
{
	int	i;

	i = 0;
	while (stack && i < place)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

void	ft_normalize(t_list **stack)
{
	int		num;
	int		size;
	t_list	*first;

	size = ft_lstsize(*stack);
	num = 0;
	while (num < size)
	{
		first = ft_lstget(*stack, ft_lstmin(stack));
		((t_data *)first->content)->rank = num;
		num++;
	}
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
	int		chunks;

	ac = ac - 1;
	a = NULL;
	b = NULL;
	chunks = 5;
	operations = 0;
	if (!ac)
		return (0);
	if (!check_int(av) || !check_dupli(ac, av))
		return (write(2, "Error\n", 6));
	create_list(&a, ac, av);
	ft_lstiter(a, &printlist);
	printf("-----------------------------\n");
	ft_normalize(&a);
	ft_lstiter(a, &printlist);
	ft_lstclear(&a, &free);
	ft_lstclear(&b, &free);
	return (0);
}
