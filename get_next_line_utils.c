/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 19:54:36 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/17 15:38:02 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*str_join(char *buffer, char *tmp)
{
	int		i;
	int		j;
	char	*str;
	int		str_length;

	i = 0;
	while (buffer && buffer[i])
		i++;
	str_length = i + BUFFER_SIZE;
	if (!(str = (char*)malloc(str_length + 1)))
		return (NULL);
	i = 0;
	j = -1;
	while (buffer && buffer[++j] != '\0')
		str[i++] = buffer[j];
	j = -1;
	while (tmp[++j] != '\0')
		str[i++] = tmp[j];
	str[i] = '\0';
	return (str);
}

int			have_a_newline(char *str)
{
	int i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char		*sub_str(char const *s, unsigned int start)
{
	char			*sub_str;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = start;
	if (start > i)
		return (NULL);
	while (s[i])
		i++;
	if (!(sub_str = (char*)malloc(i - start + 2)))
		return (NULL);
	i = start - 1;
	while (s[++i])
		sub_str[i - start] = s[i];
	sub_str[i - start] = '\0';
	return (sub_str);
}

int			get_line(char **line, char **buffer)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (*(*buffer + i) != '\n' && *(*buffer + i) != '\0')
		i++;
	if (!(*line = (char*)malloc(i + 1)))
		return (-1);
	j = -1;
	while (++j < i)
		*(*line + j) = *(*buffer + j);
	*(*line + j) = '\0';
	tmp = sub_str(*buffer, i + 1);
	if (*(*buffer) == '\0')
		return (0);
	if (*buffer)
		free(*buffer);
	*buffer = tmp;
	return (1);
}
