/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:50:23 by fdikilu           #+#    #+#             */
/*   Updated: 2017/11/25 20:56:26 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_char(int n, int base)
{
	int		len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

char		*ft_itoa_base2(int n, int base, char *strnb)
{
	int		len;

	len = ft_nb_char(n, base);
	while (len--)
	{
		strnb[len] = BASE[(n % base)];
		n /= base;
	}
	return (strnb);
}
