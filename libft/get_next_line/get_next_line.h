/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:58:35 by phnowak           #+#    #+#             */
/*   Updated: 2023/09/21 15:50:27 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(char *s);
size_t	gnl_strlcpy(char *dest, char *src, size_t n);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*read_buffer(int fd, char *read_line);
char	*read_line_untile_nl(char *read_line);
char	*deline_from_read_line(char *read_line);
char	*get_next_line(int fd);

#endif
