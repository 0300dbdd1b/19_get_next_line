/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 05:51:17 by naddino           #+#    #+#             */
/*   Updated: 2020/03/11 16:35:11 by naddino          ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
		s_len = 0;
	else
		s_len = s_len - start;
	if (s_len < len)
		len = s_len;
	if (!(output = malloc(sizeof(*s) * (len + 1)))
			|| !ft_strlcpy(output, s + start, len + 1))
		return (0);
	return (output);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*output;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(output = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	output[0] = '\0';
	ft_strlcat(output, s1, len + 1);
	ft_strlcat(output, s2, len + 1);
	return (output);
}

static char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*copy;

	if (!src)
		return (NULL);
	i = 0;
	if (!(copy = (char *)malloc((n + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0'; 
	return (copy);
}

static int	word_c(const char *str, char c)
{
	int	i;
	int	nb_word;

	nb_word = 0;
	if (str[0] != c)
		nb_word++;
	i = 1;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			nb_word++;
		i++;
	}
	return (nb_word);
}

static char	**split_free(char **tab, int k)
{
	while (k)
	{
		free(tab[k]);
		k--;
	}
	free(tab);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!s || !(tab = (char **)malloc((word_c(s, c) + 1) * sizeof(char *))))
		return (0);
	k = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j)
		{
			if (!(tab[k++] = ft_strndup((char *)&s[i], j)))
				return (split_free(tab, k - 2));
			i = i + j;
		}
		if (s[i])
			i++;
	}
	tab[k] = 0;

	return (tab);
}