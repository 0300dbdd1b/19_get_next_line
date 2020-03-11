/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:51:13 by naddino           #+#    #+#             */
/*   Updated: 2020/03/11 18:00:23 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_buff(int fd) /* lis BUFFER_SIZE characteres et les stockes dans une string */
{
    int size;
    static char buff[BUFFER_SIZE + 1];
    char *output;

    size = read(fd, buff, BUFFER_SIZE);
    if (size == 0)
        return (0);
    buff[size + 1] = '\0';
    output = ft_strdup(buff);
    return (output);
}

char *buffer_alloc(int fd, char *buffer, int count) /* Realloue et cat buffer */
{
   char *tmp;
   tmp = buffer;
   free(buffer);
   buffer = malloc(sizeof(char) * BUFFER_SIZE * count + 1);
   ft_strlcpy(buffer, tmp, BUFFER_SIZE * count + 1);
   ft_strlcat(buffer, get_buff(fd), BUFFER_SIZE * count + 1);
   return (buffer);
}

char *get_line(int fd)
{
    size_t x;
    char *buffer;
    char *output;
    int count;

    count = 2;
    x = 0;
    buffer = get_buff(fd);
    while (buffer[x++] != '\n')
    {
        if (buffer[x] == '\0' || !buffer[x])
            buffer = buffer_alloc(fd, buffer, count++);
    }
    output = malloc(sizeof(char) * x + 1);
    ft_strlcpy(output, buffer, x);
    printf("Output = %s\n", output);
    return (output);
}

int get_next_line(int fd, char **line)
{
    size_t x;
    char *output;

    x  = 0;
    if (BUFFER_SIZE <= 0)
        return (-1);
    output = get_line(fd);

}

int main()
{
    char **ok;
    int fd = open("fichier", O_RDONLY);

    while (get_next_line(fd, ok) != 0)
    {
       // write(1, "\n", 1);  
    }

}

