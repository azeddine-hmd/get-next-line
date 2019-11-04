/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 19:54:36 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/04 00:13:51 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int    str_join(char **buffer, char *tmp, int endtmp)
{
    int    i;
    int    j;

    tmp[endtmp] = '\0';
    i = 0;
    j = -1;
    if (!(*buffer))
	{
      if (!(*buffer = (char*)malloc(1)))
        return (-1);
	  buffer[0][0] = '\0';
	}
	while ((*(*buffer + i)))
        i++;
    while (tmp[++j])
        *(*buffer + i++) = tmp[j];
    *(*buffer + i) = '\0';
    if (tmp)
        free(tmp);
  return (1);
}

int		is_newline(char *str)
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

char	*sub_str(char const *s, unsigned int start)
{
	char			*sub_str;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = start;
	while (s[i])
		i++;
	if (start > i)
		return (NULL);
	if (!(sub_str = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	i = start - 1;
	while (s[++i])
		sub_str[i - start] = s[i];
	sub_str[i - start] = '\0';
	return (sub_str);
}

int		get_line(char **line, char **buffer)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (*(*buffer + i) != '\n' || *(*buffer + i) == '\0')
		i++;
	if (!(*line = (char*)malloc(i + 1)))
		return (-1);
	j = 0;
	while (j < i)
	{
		*(*line + j) = *(*buffer + j);
		j++;
	}
	*(*line + j) = '\0';
	tmp = sub_str(*buffer, i + 1);
	free(*buffer);
	*buffer = tmp;
	return (1);
}
