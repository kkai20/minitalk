/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:40:46 by kkai              #+#    #+#             */
/*   Updated: 2021/04/29 19:49:03 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*dest1;
	unsigned char	*src2;

	dest1 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest == src)
		return (dest);
	while (len > 0)
	{
		*dest1 = *src2;
		dest1++;
		src2++;
		len--;
	}
	return (dest);
}
