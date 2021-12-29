/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:12:51 by kkai              #+#    #+#             */
/*   Updated: 2021/04/29 19:46:10 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	unsigned char	a;

	if (dest == src)
	{
		return (dest);
	}
	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	a = (unsigned char)c;
	while (n > 0)
	{
		if (*p2 == a)
		{
			*p1 = *p2;
			p1++;
			return (p1);
		}
		*p1 = *p2;
		p1++;
		p2++;
		n--;
	}
	return (NULL);
}
