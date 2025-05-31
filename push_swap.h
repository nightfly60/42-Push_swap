/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:12:54 by edurance          #+#    #+#             */
/*   Updated: 2025/05/31 15:48:14 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/*utils*/
int		check_int(char **av);
int		check_dupli(int ac, char **av);
void	ft_normalize(t_list **stack);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);
void	ft_push_five(t_list **stack_a, t_list **stack_b, int maxrank, int minrank);

/*lists*/
void	create_list(t_list **stack_a, int ac, char **av);
void	ft_lstswap(t_list **stack);
void	ft_lstrotate(t_list **stack);
void	ft_lstrev_rotate(t_list **stack);
int		ft_lstsorted(t_list *stack, int prem);
int		ft_lstmin(t_list **stack);
int		ft_lstmax(t_list **stack);
t_list	*ft_lstget(t_list *stack, int place);

/*struct*/
typedef struct s_data
{
	int	value;
	int	rank;
}		t_data;

/*operations*/
void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

#endif