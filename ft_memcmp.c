/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakonukl <sakonukl@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:57:57 by sakonukl          #+#    #+#             */
/*   Updated: 2026/09/16 16:57:57 by sakonukl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n)
		&& (((const unsigned char *)s1)[i] == ((const unsigned char *)s2)[i]))
	{
		i++;
	}
	if (i != n)
		return (((const unsigned char *)s1)[i]
			- ((const unsigned char *)s2)[i]);
	return (0);
}
