/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:47:37 by kkai              #+#    #+#             */
/*   Updated: 2021/04/30 03:07:22 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		flag;
	char	c;

	flag = 1;
	if (n < 0)
	{
		flag = -1;
		write(fd, "-", 1);
	}
	if (n < 10 && n > -10)
	{
		c = (n * flag) + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10 * flag, fd);
		c = n % 10 * flag + '0';
		write(fd, &c, 1);
	}
}
