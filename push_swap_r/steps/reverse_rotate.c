/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:08:41 by hbulut            #+#    #+#             */
/*   Updated: 2025/02/27 19:36:50 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// rra (reverse rotate a): a stackinin bütün elemanlarını bir aşağı kaydırın.
// Son eleman artık ilk eleman olacaktır.

// rrb (reverse rotate b): b stackinin bütün elemanlarını bir aşağı kaydırın.
// Son eleman artık ilk eleman olacaktır.

// rrr : rra ve rrb aksiyonlarının ikisini de çalıştırır

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list	t_list;

typedef struct s_list
{
	int					value;
	t_list				*next;

}						t_list;

void	reverse_rotate_a(t_list **a)
{
	t_list *tmp;
	int i = 0;

	if (a == NULL || (*a) == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	while (tmp->next->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	if (i == 1)
		return ;
	tmp->next = NULL;
	
	
	
}



