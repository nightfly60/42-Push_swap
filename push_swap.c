/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:46:46 by edurance          #+#    #+#             */
/*   Updated: 2025/06/01 16:46:18 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(void *content)
{
	printf("%d\n", *(int *)content);
}

// int	main(int ac, char **av)
// {
// 	t_list	*a;
// 	t_list	*b;
// 	t_list	*btemp;
// 	int		temp;
// 	int		operations;
// 	int		count;
// 	int		k;
// 	int		chunks;

// 	ac = ac - 1;
// 	a = NULL;
// 	b = NULL;
// 	chunks = 5;
// 	operations = 0;
// 	if (!ac)
// 		return (0);
// 	if (!check_int(av) || !check_dupli(ac, av))
// 		return (write(2, "Error\n", 6));
// 	create_list(&a, ac, av);
// 	k = 0;
// 	while (chunks < ft_lstsize(a))
// 	{
// 		while (k < chunks)
// 		{
// 			ft_pb(&a, &b);
// 			k++;
// 			chunks += chunks;
// 			operations++;
// 		}
// 		k = 0;
// 		while (b)
// 		{
// 			while (ft_lstmax(b))
// 			{
// 				ft_rb(&b);
// 				operations++;
// 			}
// 			ft_pa(a, b);
// 			operations++;
// 		}
// 	}
// 	ft_lstiter(b, &printlist);
// 	printf("LE COMPTEUR MESDAMES ET MESSIEURS = %d", operations);
// 	ft_lstclear(&a, &free);
// 	ft_lstclear(&b, &free);
// 	return (0);
// }
