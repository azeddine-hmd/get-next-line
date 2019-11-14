/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:07:45 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/11 16:47:43 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*l_lstnew(int fd)
{
	t_list	*node;

	if (!(node = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	node->buffer = NULL;
	node->fd = fd;
	node->next = NULL;
	return (node);
}

char		**get_fd_buffer(int fd, t_list **buffers)
{
	t_list	*head;

	if (!*buffers)
	{
		if (!(*buffers = l_lstnew(fd)))
			return (NULL);
		return (&((*buffers)->buffer));
	}
	head = *buffers;
	while (head->next)
	{
		if (head->fd == fd)
			return (&(head->buffer));
		head = head->next;
	}
	if (head->fd == fd)
		return (&(head->buffer));
	if (!(head->next = l_lstnew(fd)))
		return (NULL);
	return (&((head->next)->buffer));
}

int			norminette_helper(char **line, char **buffer, char *tmp, int rr)
{
	int		line_return;

	if (rr == 0)
		free(tmp);
	if (!*buffer)
	{
		if (!(*buffer = (char*)malloc(1)))
			return (-1);
		*(*buffer) = '\0';
	}
	if ((line_return = get_line(line, buffer)) == -1)
		return (-1);
	else if (line_return == 0)
	{
		if (*buffer)
			*(*buffer) = '\0';
		return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static t_list	*buffers;
	char			**buffer;
	char			*tmp;
	char			*free_after_buffer;
	int				read_return;

	if (!line)
		return (-1);
	if (!(buffer = get_fd_buffer(fd, &buffers)))
		return (-1);
	while (!is_newline(*buffer))
	{
		if (!(tmp = (char*)malloc(BUFFER_SIZE + 1)))
			return (-1);
		if (!(read_return = read(fd, tmp, BUFFER_SIZE)))
			break ;
		else if (read_return == -1)
			return (-1);
		tmp[read_return] = '\0';
		free_after_buffer = *buffer;
		*buffer = str_join(*buffer, tmp);
		if (free_after_buffer)
			free(free_after_buffer);
	}
	return (norminette_helper(line, buffer, tmp, read_return));
}
