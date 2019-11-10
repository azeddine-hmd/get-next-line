/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:07:54 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/10 06:52:23 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_list
{
	char			*buffer;
	struct s_list	*next;
	int				fd;
}				t_list;

int				get_length(const char *s);
int				get_next_line(int fd, char **line);
char			*str_join(char *buffer, char *tmp);
int				is_newline(char *str);
char			*sub_str(char const *s, unsigned int start);
int				get_line(char **line, char **buffer);

#endif
