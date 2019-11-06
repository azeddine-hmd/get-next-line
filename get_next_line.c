/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:07:45 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/06 16:07:33 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		*tmp;
	char		*free_after_buffer;
	int			read_return;
	int			line_return;

	if (!line)
		return (-1);
	while (!is_newline(buffer))
	{
		if (!(tmp = (char*)malloc(BUFFER_SIZE + 1)))
			return (-1);
		if (!(read_return = read(fd, tmp, BUFFER_SIZE)))
		{
			if (tmp)
				free(tmp);
			break ;
		}
		else if (read_return == -1)
			return (-1);
		tmp[read_return] = '\0';
		free_after_buffer = buffer;
		buffer = str_join(buffer, tmp);
		if (free_after_buffer)
			free(free_after_buffer);
	}
	if ((line_return = get_line(line, &buffer)) == -1)
		return (-1);
	else if (line_return == 0)
	{
		if (buffer)
			free(buffer);
		return (0);
	}
	return (1);
}
