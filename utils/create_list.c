/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:53:39 by edurance          #+#    #+#             */
/*   Updated: 2025/05/28 17:29:01 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_list(t_list **stack_a, int ac, char **av)
{
	int		i;
	t_list	*new;
	int		*temp;

	i = 1;
	while (i <= ac)
	{
		temp = malloc(sizeof(int));
		if (!temp)
		{
			ft_lstclear(stack_a, &free);
			return ;
		}
		*temp = (int)ft_atoi(av[i]);
		new = ft_lstnew(temp);
		ft_lstadd_back(stack_a, new);
		i++;
	}
}
