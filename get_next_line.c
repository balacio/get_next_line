/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:00:50 by joagosti          #+#    #+#             */
/*   Updated: 2021/03/09 16:25:14 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_line(char **save, char **line)
{
	size_t			len;
	char			*tmp;

	len = 0;
	while ((*save)[len] != '\n' && (*save)[len] != '\0')
		len++;
	if ((*save)[len] == '\n')
	{
		*line = ft_substr(*save, 0, len);
		tmp = ft_strdup(&((*save)[len + 1]));
		free(*save);
		*save = tmp;
		if ((*save)[0] == '\0')
			free(save);
	}
	else
	{
		*line = ft_strdup(*save);
		free(save);
	}
	return (1);
}

static int			ft_sauce(int read_size, char **save, char **line)
{
	if (read_size < 0)
		return (-1);
	// else if (read_size == 0 && *save == NULL)
	else if (read_size == 0)
		return (0);
	else
		return (ft_line(save, line));
}

int					get_next_line(int fd, char **line)
{
	static char		*save;
	char			*tmp;
	char			buf[BUFFER_SIZE + 1];
	int				read_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	// if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
	// 	return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (buf == "")
			return (0);
		buf[read_size] = '\0';
		if (!save)
			save = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(save, buf);
			free(save);
			save = tmp;
		}
		if (ft_strchr(save, '\n'))
			break;
	}
	return (ft_sauce(read_size, &save, line));
}
