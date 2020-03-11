/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:51:00 by naddino           #+#    #+#             */
/*   Updated: 2020/03/11 15:15:20 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 3
# endif

int get_next_line(int fd, char **line);
char *get_buff(int fd);
char *get_line(int fd);
char *testbuf(int fd);
size_t		ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
void		*ft_memset(void *b, int c, size_t len);
#endif