/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasretdenizbulut <hasretdenizbulut@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:03:04 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/01 23:03:08 by hasretdeniz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*trash_free(t_list *new_lst, void (*del)(void *))
{
	ft_lstclear(&new_lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
			return (trash_free(new_lst, del));
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			free(new_content);
			return (trash_free(new_lst, del));
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
