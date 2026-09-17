/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakonukl <sakonukl@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:58:53 by sakonukl          #+#    #+#             */
/*   Updated: 2026/09/16 16:58:53 by sakonukl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	**dealloc(char **strs, size_t count)
{
	while (count > 0)
		free(strs[--count]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		i;
	const char	*start;

	if (!s)
		return (NULL);
	result = (char **)ft_calloc(count_words(s, c) + 1, sizeof (char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		start = s;
		while (*s && *s != c)
			s++;
		result[i] = ft_substr(start, 0, s - start);
		if (!result[i])
			return (dealloc(result, i));
		i++;
	}
	return (result);
}
