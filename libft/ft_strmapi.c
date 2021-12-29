/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:01:05 by kkai              #+#    #+#             */
/*   Updated: 2021/04/27 22:16:30 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*heap;

	i = 0;
	if (!s || !f)
		return (NULL);
	heap = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!heap)
		return (NULL);
	while (s[i] != '\0')
	{
		heap[i] = (*f)(i, s[i]);
		i++;
	}
	heap[i] = '\0';
	return (heap);
}
