/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 05:46:40 by fdikilu           #+#    #+#             */
/*   Updated: 2017/11/15 07:09:21 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char const *s1, char const *s2, int c)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (!(s1 && s2))
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(c >= 32 && c <= 126)
		|| !(str = (char *)malloc(sizeof(*str) * (len + 2))))
		return (ft_strjoin(s1, s2));
	while (s1[i] && (str[i] = s1[i]))
		i++;
	str[i] = c;
	i++;
	while (s2[j] && (str[i] = s2[j]))
	{
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
