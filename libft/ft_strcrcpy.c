/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcrcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 05:43:17 by fdikilu           #+#    #+#             */
/*   Updated: 2017/12/05 17:56:55 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcrcpy(char *dest, const char *src, int c)
{
	int		len;

	len = ft_strlen(src) - ft_strclen(src, c) - 1;
	return (ft_strncpy(dest, (ft_strchr(src, c) + 1), len));
}
