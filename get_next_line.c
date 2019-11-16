/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:07:45 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/14 08:30:40 by ahamdaou         ###   ########.fr       */
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

void		l_lstremove(int fd, t_list **buffers)
{
	t_list	*tmp;
	t_list	*node;
	t_list	*node_left;

	if (!*buffers)
		return ;
	if ((*buffers)->fd == fd)
	{
		free((*buffers)->buffer);
		tmp = (*buffers);
		(*buffers) = (*buffers)->next;
		free(tmp);
	}
	node = *buffers;
	while (node->next)
	{
		if (node->next->fd == fd)
		{
			node_left = node;
			node = node->next;
			free(node->buffer);
			tmp = node;
			node = node->next;
			tmp->next = NULL;
			free(tmp);
			node_left->next = node;
			return ;
		}
		node = node->next;
	}
}

int			norm(t_list **bs, char **li, char **buf, int rr, int fd)
{
	int		line_return;

	if (rr == -1)
		return (-1);
	if (rr == 0 && !*buf)
	{
		if (!(*li = (char*)malloc(1)))
			return (-1);
		*(*li) = '\0';
		l_lstremove(fd, bs);
		return (0);
	}
	if ((line_return = get_line(li, buf)) == -1)
		return (-1);
	else if (line_return == 0)
	{
		l_lstremove(fd, bs);
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

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = get_fd_buffer(fd, &buffers)))
		return (-1);
	if (!(tmp = (char*)malloc(BUFFER_SIZE + 1)))
		return (-1);
	tmp[BUFFER_SIZE] = '\0';
	read_return = 666;
	while (!have_a_newline(*buffer))
	{
		if (!(read_return = read(fd, tmp, BUFFER_SIZE)) || read_return == -1)
			break ;
		free_after_buffer = *buffer;
		*buffer = str_join(*buffer, tmp);
		if (free_after_buffer)
			free(free_after_buffer);
	}
	free(tmp);
	return (norm(&buffers, line, buffer, read_return, fd));
}
