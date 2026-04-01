/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanantenana <fanantenana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:04:47 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/01 07:58:59 by fanantenana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*cast_src;
	unsigned char	*cast_dest;

	cast_src = (unsigned char *)src;
	cast_dest = (unsigned char *)dest;
	while (n--)
	{
		*cast_dest = *cast_src;
		cast_src++;
		cast_dest++;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	if (s1)
		len_s1 = ft_strlen(s1);
	if (s2)
		len_s2 = ft_strlen(s2);
	res = malloc((len_s1 + len_s2) + 1 * sizeof(char));
	if (!res)
		return (0);
	if (s1)
		ft_memcpy(res, s1, len_s1 + 1);
	if (s2)
		ft_memcpy(res + len_s1, s2, len_s2);
	res[len_s1 + len_s2] = '\0';
	free((void *) s1);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		res = malloc(1);
		if (res)
			res[0] = '\0';
		return (res);
	}
	if (len > s_len - start)
		len = s_len - start;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s + start, len);
	res[len] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	if (!s)
		return (NULL);
	if (ch == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
