/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:53:39 by edurance          #+#    #+#             */
/*   Updated: 2025/06/07 14:45:09 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*creates a list with integers and ranks*/
void	create_list(t_list **stack_a, int ac, char **av)
{
	int		i;
	t_list	*new;
	t_data	*temp;

	i = 1;
	while (i <= ac)
	{
		temp = malloc(sizeof(t_data));
		if (!temp)
		{
			ft_lstclear(stack_a, &free);
			return ;
		}
		temp->value = (int)ft_atoi(av[i]);
		temp->rank = -1;
		new = ft_lstnew(temp);
		ft_lstadd_back(stack_a, new);
		i++;
	}
}
