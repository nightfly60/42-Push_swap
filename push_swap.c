/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:46:46 by edurance          #+#    #+#             */
/*   Updated: 2025/05/28 13:30:30 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*a;
	int	*b;

	ac = ac - 1;
	if (!ac)
		return (0);
	if (!check_int(av) || !check_dupli(ac, av) || !convert_nbr(ac, av, &a, &b))
		return (write(2, "Error\n", 6));
	free(a);
	free(b);
}
