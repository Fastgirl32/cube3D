/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <phnowak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:41:21 by phnowak           #+#    #+#             */
/*   Updated: 2023/01/12 14:14:20 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node -> content = (void *)content;
	node -> next = NULL;
	return (node);
}

/*int	main(void)
{
	t_list	*list;
	int	x = 10;

	list = ft_lstnew(&x);
	printf("Content of the list element: %d\n", *(int *)list->content);
}*/
