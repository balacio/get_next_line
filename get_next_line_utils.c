/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 19:30:15 by joagosti          #+#    #+#             */
/*   Updated: 2021/03/09 13:49:15 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		i = 0;
		j = 0;
		if ((str = (char *)malloc(sizeof(*str) * len)))
		{
			while (s1[i])
			{
				str[i] = s1[i];
				i++;
			}
			while (s2[j])
				str[i++] = s2[j++];
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}

char		*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	while (s[i])
		i++;
	if (!(dest = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (*s)
	{
		dest[i] = *s;
		s++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		++s;
	}
	if (c == '\0')
		return ((char*)s);
	return (0);
}
