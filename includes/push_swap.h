/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:22:52 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/10/04 16:27:33 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct node		*next;
}	t_node;

typedef struct s_stack {
	struct s_stack	*prev;
	int				data;
	struct s_stack	*next;
}						t_stack;

long long		ft_atoll(char *str);
int				ft_isdigit(int c);
void			push(t_stack *head, int data);
void			pop(t_stack *head);
int				ft_is_sort(long long *nums, int argc);
int				ft_max_min_int(long long *nums, int size);
long long int	*reverse_array(long long *nums, int size);

long long		ft_init_nums(char **argv, long long *nums, int argc, int size);
int				ft_checking_nums(long long *nums, int size);

char			**ft_splitter(char **argv, int argc);
char			**ft_split(char const *s, char c);

char			*ft_fd_strdup(const char *s, size_t lenword);
size_t			ft_lenword(char const *s, char c);
size_t			ft_cntword(char const *s, char c);

void			ft_stack_printer(t_stack *stack);
t_stack			*ft_init_t_stack(void);
void			ft_make_list(t_stack *head, long long *nums, int array_size);
void			ft_sort_selector(t_stack *stack_a, t_stack *stack_b);

void			ft_free(char **s, int idx);
void			ft_free_stacks(t_stack *a, t_stack *b);

int				ft_sort_two(t_stack *stack_a);
int				ft_sort_three(t_stack *stack_a);
int				ft_sort_four(t_stack *stack_a, t_stack *stack_b);
int				ft_sort_five(t_stack *a, t_stack *b);
int				ft_sort_lot(t_stack *a, t_stack *b, int hundred);

void			sa(t_stack *stack_a);
void			sb(t_stack *stack_b);
void			ss(t_stack *stack_a, t_stack *stack_b);

void			ra(t_stack *stack_a);
void			rb(t_stack *stack_b);
void			rr(t_stack *stack_a, t_stack *stack_b);
void			rra(t_stack *stack_a);
void			rrb(t_stack *stack_b);
void			rrr(t_stack *stack_a, t_stack *stack_b);

void			pa(t_stack *stack_a, t_stack *stack_b);
void			pb(t_stack *stack_a, t_stack *stack_b);
void			ft_push_last(t_stack *head, int data);
void			ft_push_first(t_stack *head, int data);

int				ft_arg_size(char **argv, int argc);

int				ft_min_finder(t_stack *stack_a, int max);
int				ft_max_finder(t_stack *stack_a);
int				ft_num_in_chunk(t_stack *stack, int max_num);
t_stack			*ft_find_last_lst(t_stack *stack);

void			ft_pop_last(t_stack *head);
int				ft_space_checker(char *argv);
int				ft_num_counter(char *argv);
int				ft_size_selector(t_stack *stack);
long long		*ft_positivizer(long long *nums, int size);
int				ft_size_stack(t_stack *head);
int				ft_error(int ret);

void			free_str(char **str);
int				ft_is_dup(long long *nums, int size);

int				ft_split_nums_size(char **splitted);

int				ft_first_finder(t_stack *stack_a, int max_num);
int				ft_second_finder(t_stack *stack_a, int max_num, int hold_first);
int				ft_f_cnt(t_stack *stack, int hold_first);
int				ft_s_cnt(t_stack *stack, int hold_second);
int				ft_num_in_chunk(t_stack *stack, int max_num);
void			ft_adjusting(t_stack *stack_a, t_stack *stack_b);
void			ft_use_frst(t_stack *a, t_stack *b, int hold_first, int half);
void			ft_use_sec(t_stack *a, t_stack *b, int hold_second, int half);
void			ft_a_to_b(t_stack *a, t_stack *b, int chk_size, int chk_mlt);
void			ft_b_to_a(t_stack *stack_a, t_stack *stack_b);

#endif
