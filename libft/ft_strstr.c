/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 04:16:44 by fdikilu           #+#    #+#             */
/*   Updated: 2017/11/22 04:08:39 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;
	int back_up_i;

	i = 0;
	j = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	while (str[i] && to_find[j])
	{
		back_up_i = i;
		while (str[i] == to_find[j])
		{
			if ((size_t)j == (ft_strlen(to_find) - 1))
				return ((char *)&str[i - j]);
			j++;
			i++;
		}
		i = back_up_i;
		i = i + 1;
		j = 0;
	}
	return (0);
}
