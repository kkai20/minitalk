/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:17:46 by kkai              #+#    #+#             */
/*   Updated: 2021/04/29 19:46:58 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	a;

	p = (unsigned char *)s;
	a = (unsigned char)c;
	while (n)
	{
		if (*p == a)
			return (p);
		p++;
		n--;
	}
	return (NULL);
}
