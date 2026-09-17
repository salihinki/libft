/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakonukl <sakonukl@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:59:13 by sakonukl          #+#    #+#             */
/*   Updated: 2026/09/16 16:59:13 by sakonukl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *buf, const char *src, size_t bufsize)
{
	size_t	buf_len;
	size_t	src_index;
	size_t	src_len;

	buf_len = 0;
	src_index = 0;
	src_len = ft_strlen(src);
	while (buf_len < bufsize && buf[buf_len])
		buf_len++;
	if (bufsize != buf_len)
	{
		while (src[src_index] && src_index < ((bufsize - buf_len) - 1))
		{
			buf[buf_len + src_index] = src[src_index];
			src_index++;
		}
		buf[buf_len + src_index] = '\0';
	}
	return (buf_len + src_len);
}
