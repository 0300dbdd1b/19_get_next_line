/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:51:13 by naddino           #+#    #+#             */
/*   Updated: 2020/02/24 07:44:54 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_line(int fd)
{
    int size;
    static char buff[BUFFER_SIZE + 1];
    size = read(fd, buff, BUFFER_SIZE);
    buff[size] = '\0';
    printf("%d\n", size);
    return (buff);
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