/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:04:18 by kkai              #+#    #+#             */
/*   Updated: 2021/04/28 13:39:24 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	else
	{
		p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (p == NULL)
			return (NULL);
		i = -1;
		while (s1[++i] != '\0')
			p[i] = s1[i];
		j = 0;
		while (s2[j] != '\0')
			p[i++] = s2[j++];
		p[i] = '\0';
	}
	return (p);
}
