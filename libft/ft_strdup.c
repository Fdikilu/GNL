/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:43:39 by fdikilu           #+#    #+#             */
/*   Updated: 2017/11/22 03:46:59 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		srclen;
	char	*str;

	srclen = ft_strlen(src);
	str = (char *)malloc(sizeof(*str) * (srclen + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i = i + 1;
	}
	str[i] = '\0';
	return (str);
}
