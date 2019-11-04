/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:07:54 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/03 23:15:15 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		str_join(char **buffer, char *tmp, int endtmp);
int		is_newline(char *str);
char	*sub_str(char const *s, unsigned int start);
int		get_line(char **line, char **buffer);

#endif
