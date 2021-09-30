/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:28:17 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/30 11:06:28 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_cntword(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s && *s != c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
		while (*s && *s == c)
			s++;
	}
	return (cnt);
}

size_t	ft_lenword(char const *s, char c)
{
	size_t	lenword;

	lenword = 0;
	while (*s && *s++ != c)
		lenword++;
	return (lenword);
}

char	*ft_fd_strdup(const char *s, size_t lenword)
{
	char	*arr;
	size_t	idx;

	idx = 0;
	arr = (char *)malloc(sizeof(char) * (lenword + 1));
	if (!arr)
		return (0);
	while (idx < lenword)
	{
		arr[idx] = s[idx];
		idx++;
	}
	arr[idx] = 0;
	return (arr);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int		ft_split_arr_size(char **split_arr)
{
	int idx;

	idx = 0;
	while (split_arr[idx])
		idx++;
	return (idx);
}

char	**ft_splitter(char **argv, int argc)
{
	char	**splitted;
	int		i;
	int		splitted_size;
	int		size;

	i = 0;
	size = 0;
	splitted = NULL;
	while (i < argc)
	{
		
		splitted = ft_split(argv[i], ' ');
		splitted_size = ft_split_arr_size(splitted);
		size += splitted_size;
		i++;
	}
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	cntword;
	size_t	lenword;
	size_t	aidx;

	cntword = ft_cntword(s, c);
	arr = (char **)malloc(sizeof(char *) * (cntword + 1));
	aidx = 0;
	while (aidx < cntword)
	{
		while (*s && *s == c)
			s++;
		lenword = ft_lenword(s, c);
		arr[aidx] = ft_fd_strdup(s, lenword);
		if (!arr[aidx])
		{
			ft_free(arr, aidx - 1);
			return (0);
		}
		aidx++;
		s += lenword;
	}
	arr[cntword] = 0;
	return (arr);
}
