/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakonukl <sakonukl@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:59:05 by sakonukl          #+#    #+#             */
/*   Updated: 2026/09/16 16:59:05 by sakonukl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;
	unsigned int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	index = 0;
	if (s)
	{
		while (index < len)
		{
			(*f)(index, s + index);
			index++;
		}
	}
}
