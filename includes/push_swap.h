#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct node
{

    int data;
    struct node* next;
} node;

typedef struct s_stack {
    struct s_stack* prev;
    int data;
    struct s_stack* next;
}t_stack;


int ft_atoll(char *str);
int	ft_isdigit(int c);
void    push(t_stack *head, int data);
void pop(t_stack *head);
int invert_array(int *nums);
int ft_is_sort(long long *array, int argc);
long long int *reverse_array(long long *nums, int size);

char **ft_splitter(char **argv, int argc);
char		**ft_split(char const *s, char c);

char		*ft_fd_strdup(const char *s, size_t lenword);
size_t		ft_lenword(char const *s, char c);
size_t		ft_cntword(char const *s, char c);
void	ft_bzero(void *s, size_t n);

void ft_stack_printer(t_stack *stack);
t_stack *ft_init_t_stack(void);
void ft_make_list(t_stack *head, long long *nums, int array_size);
void	ft_sort_selector(t_stack *stack_a, t_stack *stack_b);

void		ft_free(char **s, int idx);
void	ft_free_stacks(t_stack *a, t_stack *b);

int ft_sort_two(t_stack *stack_a);
int ft_sort_three(t_stack *stack_a);
int ft_sort_four(t_stack *stack_a, t_stack *stack_b);
int ft_sort_five(t_stack *a, t_stack *b);
int ft_sort_lot(t_stack *a, t_stack *b);

void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);

void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack *stack_a);
void    rrb(t_stack *stack_b);
void    rrr(t_stack *stack_a, t_stack *stack_b);

void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);
void	ft_push_last(t_stack *head, int data);
void	ft_push_first(t_stack *head, int data);

int		ft_split_arr_size(char **split_arr);
int     ft_arg_size(char **splitted);
int     ft_args_array(char **splitted, t_stack *a, int size, int argv_or_splitted);

int ft_min_finder(t_stack *stack_a, int max);
int ft_max_finder(t_stack *stack_a);
int ft_num_in_chunk(t_stack *stack, int max_num);
t_stack	*ft_find_last_lst(t_stack *stack);

void	ft_pop_last(t_stack *head);
int ft_space_checker(char *argv);
int ft_num_counter(char *argv);
int ft_size_selector(t_stack *stack);
long long *ft_positivizer(long long *nums, int size);
int ft_size_stack(t_stack *head);
void ft_error(char *str);

int ft_is_dup(long long *nums, int size);



#endif