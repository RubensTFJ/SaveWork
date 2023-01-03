/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:46:29 by rteles-f          #+#    #+#             */
/*   Updated: 2022/12/04 16:58:14 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*seek_line(int fd, int pos, char *piece, char *save)
{
	int		i;
	char	buffer[BUFFER_SIZE + 1];
	char	*line;

	i = 0;
	while (i <= BUFFER_SIZE)
		buffer[i++] = 0;
	i = 0;
	while (piece && piece[i] && piece[i] != '\n')
		i++;
	if (piece && piece[i] != '\n' && read(fd, buffer, BUFFER_SIZE) > 0)
		line = seek_line(fd, (pos + i), buffer, save);
	else
	{
		line = malloc(sizeof(char) * (pos + i + (piece[i] == '\n') + 1));
		if (!line)
			return (NULL);
		line[pos + i + (piece[i] == '\n')] = '\0';
		over_read(piece, save);
	}
	i = 0;
	while (line && piece && piece[i] && (i == 0 || piece[i - 1] != '\n'))
		line[pos++] = piece[i++];
	return (line);
}

void	over_read(char *string, char *save)
{
	int	i;
	int	j;

	i = 0;
	while (string && string[i] && string[i] != '\n')
		i++;
	if (string)
		i += string[i] == '\n';
	j = 0;
	while (string && string[i])
		save[j++] = string[i++];
	while (save && save[j])
		save[j++] = 0;
}
