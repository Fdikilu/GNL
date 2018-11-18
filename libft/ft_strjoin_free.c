/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:02:35 by fdikilu           #+#    #+#             */
/*   Updated: 2017/12/11 16:50:07 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!(s1 && s2))
		return (NULL);
	i = 0;
	j = 0;
	if (!(str = (char *)malloc(sizeof(*str)
		* (ft_strlen(s1) + ft_strlen((char *)s2) + 1))))
		return (NULL);
	while (s1[i] && (str[i] = s1[i]))
		i++;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	ft_strdel((char **)&s1);
	return (str);
}
