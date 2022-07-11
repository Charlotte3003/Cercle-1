/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:09:48 by cbourre           #+#    #+#             */
/*   Updated: 2022/05/16 22:06:21 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_len_line(char *sch)
{
	int	i;

	i = 0;
	while (sch[i])
	{
		if (sch[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int				i;
	unsigned char	c1;

	i = 0;
	c1 = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == c1)
			return ((char *)s + i);
		i++;
	}
	if (c1 == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s == 0 || !len)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
