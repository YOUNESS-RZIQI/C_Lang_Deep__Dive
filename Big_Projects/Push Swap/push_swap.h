/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:23:15 by yrziqi            #+#    #+#             */
/*   Updated: 2025/12/23 04:50:25 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				val;
	int				index;
	struct s_node	*previos;
	struct s_node	*next;
}					t_node;

t_node				*input(int argc, char *argv[]);
short				is_null_or_s_full_spaces(int argc, char *argv[]);
size_t				s_length(char *s);
short				is_space(char c);
void				free_dll(t_node *head);
int					ft_atoi(const char *s, short *is_fail);
short				is_digit_for_char(char c);
char				**ft_split(char const *s, char c);
short				is_there_is_more_then_sub_add(char *s);
short				is_error_in_input(t_node *stack_a);
void				put_index(t_node *stack_a);
size_t				dll_length(t_node *head);
short				is_sorted_list(t_node *stack_a);
t_node				*tail_node(t_node *head);
void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);
void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_b, t_node **stack_a);
void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				rra(t_node **stack_a);
void				rrb(t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);
void				sorting(t_node **stack_a, t_node **stack_b);
void				lowest_index_in_stack(t_node *stack, int *highest_index);
int					get_index_pos_in_stack(t_node *stack, int index);
int					get_range(int len);
void				pull_back_to_stack_a(t_node **stack_a, t_node **stack_b);

#endif