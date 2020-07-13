/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:51:00 by naddino           #+#    #+#             */
/*   Updated: 2020/03/11 18:00:56 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef   BUFFER_SIZE
#   define BUFFER_SIZE 4
# endif

int get_next_line(int fd, char **line);
char    *get_buff(const int fd);
char    **get_line(const int fd, char *output);
char    *get_endl(const int fd, const int i);
int     checkRet(const char *str);

size_t		ft_strlen(const char *s);
size_t	    ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char	    *ft_strdup(const char *s1);
void		*ft_memset(void *b, int c, size_t len);
char	    *ft_substr(char const *s, unsigned int start, size_t len);
char        *ft_strjoin(char const *s1, char const *s2);
static char	*ft_strndup(char *src, int n);
static int	word_c(const char *str, char c);
char		**ft_split(char const *s, char c);

#endif