/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:29:05 by fdikilu           #+#    #+#             */
/*   Updated: 2018/02/22 23:05:08 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static int		nb_cline(char *buf)
{
	int		nb_char;

	nb_char = 0;
	while (buf[nb_char])
	{
		if (buf[nb_char] == '\n')
			return (nb_char);
		nb_char++;
	}
	return (nb_char);
}

static t_save	*new_save(int fd)
{
	t_save			*new;

	new = NULL;
	if (!(new = (t_save *)malloc(sizeof(*new))))
		return (NULL);
	new->rest = ft_strnew(0);
	new->fd = fd;
	return (new);
}

static t_save	*check_l_save(t_list **l_save, int fd)
{
	t_list			*tmp;

	tmp = NULL;
	if (!(*l_save))
	{
		*l_save = ft_lstnew(new_save(fd), sizeof(t_save));
		return ((*l_save)->content);
	}
	tmp = *l_save;
	while (tmp)
	{
		if (((t_save *)tmp->content)->fd == fd)
			return (tmp->content);
		tmp = tmp->next;
	}
	ft_lstadd(l_save, ft_lstnew(new_save(fd), sizeof(t_save)));
	return ((*l_save)->content);
}

static int		rest_in_line(char **line, char **ctmp, char *rest)
{
	char	*next;

	if (!rest || !(*rest))
		return (0);
	next = ft_strsub(ft_strchr(rest, '\n'), 1, ft_strlen(rest)
		- nb_cline(rest));
	if (next)
	{
		(rest)[nb_cline(rest)] = '\0';
		*ctmp = ft_strjoin_free(*ctmp, rest);
		rest = ft_strcpy(rest, next);
		free((void *)next);
		*line = ft_strdup(*ctmp);
		free((void *)*ctmp);
		return (1);
	}
	else
	{
		*ctmp = ft_strjoin_free(*ctmp, rest);
		ft_strclr(rest);
		return (0);
	}
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	t_save			*tmp;
	char			*ctmp;
	static t_list	*l_save = NULL;
	char			buf[BUFF_SIZE + 1];

	if (tmp)
		free((void *)tmp);
	if (!line || !(tmp = check_l_save(&l_save, fd)))
		return (-1);
	if ((ctmp = ft_strnew(0)) && rest_in_line(line, &ctmp, tmp->rest))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		if (!(buf[ret] = '\0') && (ret == nb_cline(buf)))
			ctmp = ft_strjoin_free(ctmp, buf);
		else
		{
			ft_strdel(&tmp->rest);
			tmp->rest = ft_strsub(ft_strchr(buf, '\n'), 1, ret - 1);
			buf[nb_cline(buf)] = '\0';
			*line = ft_strjoin_free(ctmp, buf);
			return (1);
		}
	*line = ft_strdup(ctmp);
	free((void *)ctmp);
	if ((ft_strlen(*line)) > 0)
		return (1);
	return ((ret == 0) ? 0 : -1);
}
