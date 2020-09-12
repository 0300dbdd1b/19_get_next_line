/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:57:40 by nsahloum          #+#    #+#             */
/*   Updated: 2020/02/11 19:14:57 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(char *str, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;
	int		i;
	char	*tmp;

	i = 0;
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, buff);
		free(tmp);
		while (str[i])
		{
			if (str[i] == '\n')
				return (str);
			i++;
		}
	}
	return (str);
}

int		ft_until_n(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	int			i;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, str[fd], 0) < 0 || !line
		|| fd >= OPEN_MAX)
		return (-1);
	if (str[fd] == NULL || ft_strchrn(str[fd]) == 0)
		str[fd] = ft_read_file(str[fd], fd);
	if (str[fd] == NULL)
		return (*line = ft_strdup("")) != NULL ? 0 : -1;
	i = ft_until_n(str[fd]);
	*line = ft_substr(str[fd], 0, i);
	if (str[fd] != NULL && str[fd][i] == '\n')
	{
		tmp = str[fd];
		str[fd] = ft_substr(tmp, i + 1, ft_strlen(tmp));
		free(tmp);
		return (1);
	}
	free(str[fd]);
	str[fd] = NULL;
	return (0);
}
