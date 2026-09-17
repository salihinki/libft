/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakonukl <sakonukl@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:58:04 by sakonukl          #+#    #+#             */
/*   Updated: 2026/09/16 16:58:04 by sakonukl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*source;
	char		*destination;

	source = (const char *)src;
	destination = (char *)dst;
	if (!destination && !source)
		return (NULL);
	if (source < destination)
	{
		while (len > 0)
		{
			len--;
			destination[len] = source[len];
		}
	}
	else if (source > destination)
		ft_memcpy(dst, src, len);
	return (dst);
}
