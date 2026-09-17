/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakonukl <sakonukl@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:51:32 by sakonukl          #+#    #+#             */
/*   Updated: 2026/09/16 16:51:36 by sakonukl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((size) && count > ((size_t)-1 / size))
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (ptr);
	return (ft_memset(ptr, '\0', count * size));
}
