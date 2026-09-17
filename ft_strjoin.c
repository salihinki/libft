/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakonukl <sakonukl@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:59:09 by sakonukl          #+#    #+#             */
/*   Updated: 2026/09/16 16:59:09 by sakonukl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joint = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!joint)
		return (NULL);
	ft_memcpy(joint, s1, len1);
	ft_memcpy(joint + len1, s2, len2);
	joint[len1 + len2] = '\0';
	return (joint);
}
