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


int	ft_atoi(const char *str);
int	ft_isdigit(int c);
void push(t_stack *head, int data);
void pop(t_stack *head);
int invert_array(int *nums);
void	ft_push_first(t_stack *head, int data);
int ft_is_sort(int *array);
int *reverse_array(int *nums, int size);

#endif