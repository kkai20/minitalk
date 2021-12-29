/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:58:21 by kkai              #+#    #+#             */
/*   Updated: 2021/04/29 19:54:08 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src2;

	dest1 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest1 == src2)
		return (dest);
	if (dest1 < src2)
	{
		while (n-- > 0)
			*dest1++ = *src2++;
	}
	else
	{
		dest1 += n - 1;
		src2 += n - 1;
		while (n-- > 0)
			*dest1-- = *src2--;
	}
	return (dest);
}
