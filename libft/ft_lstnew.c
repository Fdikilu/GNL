/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 01:07:45 by fdikilu           #+#    #+#             */
/*   Updated: 2017/11/28 19:59:32 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = NULL;
	if (!(lst = (t_list *)malloc(sizeof(*lst))))
		return (lst);
	if (content == NULL)
		lst = &((t_list){NULL, 0, NULL});
	else
	{
		if (!(lst->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
		lst->next = NULL;
	}
	return (lst);
}
