/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <phnowak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:25:47 by phnowak           #+#    #+#             */
/*   Updated: 2023/01/12 14:20:10 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lst_len;
	t_list	*current;

	lst_len = 0;
	current = lst;
	if (current == NULL)
		return (0);
	while (current)
	{
		current = current -> next;
		lst_len ++;
	}
	return (lst_len);
}
