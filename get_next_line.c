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
	static l_list	*buffers;
	char		*tmp;
	char		*buffer;
	char		*free_after_buffer;
	int		read_return;
	int		line_return;

	buffer = get_fd_buffer(fd, &buffers);
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
		free(buffer);
		buffer = head;
		return (0);
	}
	return (1);
}

char		*get_fd_buffer(int fd, l_list **buffers)
{
	l_list		*head;

	head = *buffers;
	if (!head)
		return (l_lstadd_front(buffers, fd));
	while (head)
	{
		if (head->fd == fd)
			return (head->buffer);
		head = head->next;
	}
	return (l_lstadd_back(buffers, fd));
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!*alst)
		ft_lstadd_front(alst, new);
	else
		//(ft_lstlast(*alst))->next = new;
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (*alst)
		new->next = *alst;
	*alst = new;
}
