/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:34:58 by kkai              #+#    #+#             */
/*   Updated: 2021/05/04 19:09:43 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int		i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n != '\0')
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*num_con(long int n, char *heap, int len)
{
	int		len_tmp;
	char	tmp;

	len_tmp = len;
	if (n < 0)
	{
		heap[0] = '-';
		n *= -1;
	}
	if (n == 0)
		heap[0] = '0';
	while (n != 0)
	{
		tmp = (n % 10) + '0';
		n /= 10;
		heap[len - 1] = tmp;
		len--;
	}
	heap[len_tmp] = '\0';
	return (heap);
}

char	*ft_itoa(int n)
{
	char	*heap;
	int		len;

	n = (long int)n;
	len = num_len(n);
	heap = (char *)malloc(sizeof(char) * (len + 1));
	if (heap == NULL)
		return (NULL);
	heap = num_con(n, heap, len);
	return (heap);
}
