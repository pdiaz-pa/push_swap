/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:56:40 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/24 15:16:23 by pdiaz-pa         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	neg;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] == 32 || str[i] == 10 || str[i] == 9 || str[i] == 12 ||
			str[i] == 13 || str[i] == 11)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * neg);
}

int	ft_isdigit(int c)
{
	if ((c > 47 && c < 58) || c == '-')
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