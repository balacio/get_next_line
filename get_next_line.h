/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 19:30:30 by joagosti          #+#    #+#             */
/*   Updated: 2021/03/09 18:41:53 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int					get_next_line(int fd, char **line);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
int					ft_strlen(const char *s);

#endif
