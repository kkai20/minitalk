/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:10:45 by kkai              #+#    #+#             */
/*   Updated: 2021/04/30 04:39:37 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	if (set[i] == '\0')
		return (ft_strdup((char *)s1));
	j = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (s1[i] != '\0' && ft_strchr(set, s1[j]))
		j--;
	p = (char *)malloc(sizeof(char) * (j - i + 2));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, &s1[i], j - i + 2);
	return (p);
}
