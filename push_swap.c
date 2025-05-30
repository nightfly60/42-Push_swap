/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:46:46 by edurance          #+#    #+#             */
/*   Updated: 2025/05/30 12:11:16 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	printlist(void *content)
// {
// 	printf("%d\n", *(int *)content);
// }

// int	main(int ac, char **av)
// {
// 	t_list	*a;
// 	t_list	*b;
// 	t_list	*btemp;
// 	int		temp;
// 	int		operations;
// 	int		count;
// 	int		k;

// 	ac = ac - 1;
// 	a = NULL;
// 	b = NULL;
// 	operations = 0;
// 	if (!ac)
// 		return (0);
// 	if (!check_int(av) || !check_dupli(ac, av))
// 		return (write(2, "Error\n", 6));
// 	create_list(&a, ac, av);
// 	while (a)
// 	{
// 		k = 0;
// 		count = ft_lstmin(&a);
// 		if (count > ft_lstsize(a) / 2)
// 		{
// 			count = ft_lstsize(a) - count;
// 			while (k < count)
// 			{
// 				ft_rra(&a);
// 				operations++;
// 				k++;
// 			}
// 		}
// 		else
// 			while (k < count)
// 			{
// 				ft_ra(&a);
// 				operations++;
// 				k++;
// 			}
// 		ft_pb(&a, &b);
// 		operations++;
// 	}
// 	ft_lstiter(b, &printlist);
// 	printf("LE COMPTEUR MESDAMES ET MESSIEURS = %d", operations);
// 	ft_lstclear(&a, &free);
// 	ft_lstclear(&b, &free);
// 	return (0);
// }
