/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:51:13 by naddino           #+#    #+#             */
/*   Updated: 2020/03/11 15:20:39 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_buff(int fd) /* lis BUFFER_SIZE characteres et les stockes dans une string */
{
    size_t size;
    static char buff[BUFFER_SIZE + 1];

    size = read(fd, buff, BUFFER_SIZE);
    buff[size + 1] = '\0';
    return (buff);
}

char *buffer_alloc(int fd, char *buffer, int count) /* Realloue et cat buffer */
{
    char *tmp;

    printf("%s\n", buffer);
    tmp = buffer;
    if (count == 2)
        buffer = malloc(sizeof(char) * ((BUFFER_SIZE * count) + 1));
    free(buffer);
    buffer = malloc(sizeof(char) * ((BUFFER_SIZE * count) + 1));
    ft_strlcpy(buffer, tmp, BUFFER_SIZE);
    ft_strlcat(buffer, get_buff(fd), BUFFER_SIZE);
    count++;

    return (buffer);
}

char *get_line(int fd)
{
    size_t x;
    char *buffer;
    static int count;

    count = 2;
    x = 2;
    buffer = get_buff(fd);
    while (buffer[x] != '\n')
    {
        if (buffer[x] == '\0' || !buffer[x])
        {
            printf("KEY\n");
            buffer_alloc(fd, buffer, count++);
        }
        x++;
    }
    printf("YES\n");
    return (buffer);
}

int get_next_line(int fd, char **line)
{
    if (BUFFER_SIZE <= 0)
        return (-1);
    printf("%s\n", get_line(fd)); 
}

int main()
{
    char **ok;
    int fd = open("fichier", O_RDONLY);
    get_next_line(fd, ok);
}

