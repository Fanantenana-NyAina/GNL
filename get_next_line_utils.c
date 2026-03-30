/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:04:47 by fananrak          #+#    #+#             */
/*   Updated: 2026/03/30 13:43:22 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	res = ft_calloc((len_s1 + len_s2) + 1, sizeof(char));
	if (!res)
		return (0);
	if (s1)
		ft_strlcat(res, s1, len_s1 + 1);
	if (s2)
		ft_strlcat(res, s2, len_s1 + (len_s2 + 1));
	return (res);
}
