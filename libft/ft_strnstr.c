/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:36:40 by fdikilu           #+#    #+#             */
/*   Updated: 2017/11/22 04:22:04 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	int i;
	int j;
	int back_up_i;

	i = 0;
	j = 0;
	if (ft_strlen(find) == 0)
		return ((char *)str);
	while ((str[i] && i != (int)len) && find[j])
	{
		back_up_i = i;
		while ((str[i] == find[j]) && i != (int)len)
		{
			if ((size_t)j == (ft_strlen(find) - 1))
				return ((char *)&str[i - j]);
			j++;
			i++;
		}
		i = back_up_i;
		i++;
		j = 0;
	}
	return (0);
}
