/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:51:17 by naddino           #+#    #+#             */
/*   Updated: 2020/03/11 14:47:57 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t x;

	x = 0;
	while (*s++)
		x++;
	return (x);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;

	if (!dest || !src)
		return (ft_strlen(dest) + ft_strlen(src));
	dest_len = ft_strlen(dest);
	if (size == 0)
		return (ft_strlen(src));
	if ((int)size < 0)
		size = dest_len + ft_strlen(src) + 1;
	i = 0;
	while (dest_len + i < size - 1 && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	size = (size > dest_len) ? dest_len : size;
	return (size + ft_strlen(src));
}

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t srclen;

	if (!src || !dst)
		return (0);
	srclen = ft_strlen(src);
	if (srclen + 1 < size)
		ft_memcpy(dst, src, srclen + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srclen);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = -1;
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (++i < n)
		ptr_dst[i] = ptr_src[i];
	return (&dst[0]);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(s1);
	if (!(dest = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_memcpy(dest, s1, size);
	return (dest);
}

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len--)
		*str++ = (unsigned char)c;
	return (b);
}