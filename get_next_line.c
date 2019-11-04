/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:07:45 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/04 00:24:50 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		*tmp;
	int			read_return;

	if (!line)
		return (-1);
	while (!is_newline(buffer))
	{
		if (!(tmp = (char*)malloc(BUFFER_SIZE + 1)))
			return (-1);
		read_return = read(fd, tmp, BUFFER_SIZE);
		if (read_return == -1)
			return (-1);
		str_join(&buffer, tmp, read_return);
	}
	if (get_line(line, &buffer) < 0)
		return (-1);
	return (1);
}
