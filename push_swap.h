/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:12:54 by edurance          #+#    #+#             */
/*   Updated: 2025/06/06 18:38:20 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/*struct*/
typedef struct s_data
{
	int	value;
	int	rank;
}		t_data;

/*operations*/
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/*checks*/
int		check_dupli(int ac, char **av);
int		check_int(char **av);

/*creation*/
void	create_list(t_list **stack_a, int ac, char **av);
void	ft_normalize(t_list **stack);

/*lists*/
t_list	*ft_lstget(t_list *stack, int place);
int		ft_lstmax(t_list **stack);
int		ft_lstmin(t_list **stack);
int		ft_lstsorted(t_list *stack, int prem);
void	ft_lstswap(t_list **stack);
void	ft_lstrotate(t_list **stack);
void	ft_lstrev_rotate(t_list **stack);

/*make operations*/
void	apply_min(t_list **a, t_list **b);
int		total_operations(int *tab);
int		*operations(t_list *a, t_list *b, int x, int rank);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
void sort_three(t_list **a);

#endif