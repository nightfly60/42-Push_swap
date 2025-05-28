/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:46:46 by edurance          #+#    #+#             */
/*   Updated: 2025/05/28 19:35:30 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	ac = ac - 1;
	a = NULL;
	b = NULL;
	if (!ac)
		return (0);
	if (!check_int(av) || !check_dupli(ac, av))
		return (write(2, "Error\n", 6));
	create_list(&a, ac, av);
}
