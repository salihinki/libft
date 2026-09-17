/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakonukl <sakonukl@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:57:43 by sakonukl          #+#    #+#             */
/*   Updated: 2026/09/16 16:57:43 by sakonukl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (new_content)
		{
			new_node = ft_lstnew(new_content);
			if (new_node)
			{
				ft_lstadd_back(&new_list, new_node);
				lst = lst->next;
				continue ;
			}
			del(new_content);
		}
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	return (new_list);
}
