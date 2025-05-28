/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:12:54 by edurance          #+#    #+#             */
/*   Updated: 2025/05/28 13:13:57 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/*utils*/
int	convert_nbr(int ac, char **av, int **stack_a, int **stack_b);
int	check_int(char **av);
int	check_dupli(int ac, char **av);

#endif