/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:50:14 by kkai              #+#    #+#             */
/*   Updated: 2021/04/30 04:33:02 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*str1;
	char	c1;
	char	*ptr;

	str1 = (char *)str;
	c1 = (char)c;
	ptr = NULL;
	i = 0;
	while (str[i])
	{
		if (str1[i] == c1)
			ptr = (char *)&str[i];
		i++;
	}
	if (str1[i] == c1)
		return ((char *)&str[i]);
	return ((char *)ptr);
}
