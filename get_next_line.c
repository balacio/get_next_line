/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:00:50 by joagosti          #+#    #+#             */
/*   Updated: 2021/03/09 18:51:20 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_return(char *str1)
{
	if (!str1)
		return (0);
	if (!ft_strchr(str1, '\n'))
		return (0);
	else
		return (1);
}

static char			*ft_sauce(char *str1, char *str2)
{
	char			*tmp;

	if (!str1)
		str1 = ft_strdup(str2);
	else
	{
		tmp = ft_strjoin(str1, str2);
		free(str1);
		str1 = tmp;
	}
	return (str1);
}

static char			*ft_line(char *str1)
{
	char			*tmp;
	int				i;

	i = 0;
	if (!str1)
		return (0);
	while (str1[i] && str1[i] != '\n')
		i++;
	if (!(tmp = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str1[i] && str1[i] != '\n')
	{
		tmp[i] = str1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char			*ft_save(char *str1)
{
	char			*tmp;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (!str1)
		return (0);
	while (str1[i] && str1[i] != '\n')
		i++;
	if (!str1[i])
	{
		free(str1);
		return (0);
	}
	if (!(tmp = malloc(sizeof(char) * ((ft_strlen(str1) - i) + 1))))
		return (0);
	i++;
	while (str1[i])
		tmp[j++] = str1[i++];
	tmp[j] = '\0';
	free(str1);
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*save;
	int				reading;

	reading = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (reading != 0 && !ft_return(save))
	{
		if ((reading = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[reading] = '\0';
		save = ft_sauce(save, buf);
	}
	free(buf);
	*line = ft_line(save);
	save = ft_save(save);
	if (reading == 0)
		return (0);
	return (1);
}
