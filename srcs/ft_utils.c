/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:56:40 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/27 16:39:28 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

int			ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == 'r' ||
	c == '\t' || c == '\v' || c == ' ');
}

int			ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_atoll(char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (ft_isalpha(*str))
		ft_error(0);
	return (sign * result);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9')|| c == '-')
	{
		return (1);
	}
	else
		return (0);
}

long long int *reverse_array(long long *nums, int size)
{
   int i;
   int t;
   int k;
   
   i = 0;
   t = 0;
   k = 0;
   while(k < (size / 2))
   {
    t = nums[i];                  // Swapping
    nums[i] = nums[size-k-1];
    nums[size-k-1] = t;
    k++;
    i++;
   }
  return(nums);
}

int ft_is_sort(long long *array, int size)
{
	int i;
	int j;
	int k;
	
	i = 0;
	j = 0;
	k = 0;
	
	
	while (i < (size - 1)) 
		i++;
	while (k < i)
	{
		
		if(array[k] >= array[k + 1])
			j++;
		k++;
	}
	if (j == i)
		return(-1);
	else
		return(0);
}