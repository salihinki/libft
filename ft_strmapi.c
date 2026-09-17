/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakonukl <sakonukl@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:59:27 by sakonukl          #+#    #+#             */
/*   Updated: 2026/09/16 16:59:27 by sakonukl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	size_t	len;
	char	*ptr;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	index = 0;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (index < len)
	{
		ptr[index] = ((*f)(index, s[index]));
		index++;
	}
	ptr[index] = 0;
	return (ptr);
}
