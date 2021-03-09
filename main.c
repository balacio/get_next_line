/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:29:24 by joagosti          #+#    #+#             */
/*   Updated: 2021/02/27 14:48:34 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main()
{
	int fd;
	char *line;

	fd = open("text.t", O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line) == 1)
		;
}
