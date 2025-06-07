/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:05:07 by edurance          #+#    #+#             */
/*   Updated: 2025/06/07 16:05:30 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	check_args(char ***av, int *args)
{
	char	*temp;

	if (*args == 1)
	{
		temp = ft_strjoin("push_swap ", (*av)[1]);
		*av = ft_split(temp, ' ');
		*args = tab_size(*av) - 1;
		free(temp);
	}
}
