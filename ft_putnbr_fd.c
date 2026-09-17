/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakonukl <sakonukl@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:58:43 by sakonukl          #+#    #+#             */
/*   Updated: 2026/09/16 16:58:43 by sakonukl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	l;
	char	c;

	l = n;
	if (l < 0)
	{
		l = -l;
		write(fd, "-", 1);
	}
	if (l > 9)
		ft_putnbr_fd(l / 10, fd);
	c = l % 10 + '0';
	write(fd, &c, 1);
}
