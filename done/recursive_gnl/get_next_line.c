/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:46:00 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/29 18:45:46 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		saved[BUFFER_SIZE + 1];
	char			buffer[BUFFER_SIZE + 1];
	char			*line;
	int				i;

	if (read(fd, 0, 0) < 0)
	{
		over_read(NULL, saved);
		return (NULL);
	}
	i = -1;
	line = NULL;
	if (!saved[0])
		i = read(fd, buffer, BUFFER_SIZE);
	else
		while (saved[++i])
			buffer[i] = saved[i];
	buffer[i] = 0;
	if (i)
		line = seek_line(fd, 0, buffer, saved);
	return (line);
}
