/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 23:52:04 by fdikilu           #+#    #+#             */
/*   Updated: 2017/11/15 04:43:04 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) == 0)
		return (ft_strnew(0));
	i = 0;
	j = ft_strlen((char *)s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (ft_strlen((char *)s) == i)
		return (ft_strnew(0));
	while (s[j] && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
		j--;
	str = ft_strsub(s, i, (size_t)(j - i + 1));
	return (str);
}
