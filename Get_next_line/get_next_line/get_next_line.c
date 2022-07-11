/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:23:52 by cbourre           #+#    #+#             */
/*   Updated: 2022/05/16 22:20:22 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_bytes(int fd, char *sch)
{
	int		read_bytes;
	char	*buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	*buf = 0;
	read_bytes = 1;
	while (!ft_strchr(sch, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		buf[read_bytes] = '\0';
		sch = ft_strjoin(sch, buf);
	}
	free(buf);
	return (sch);
}

char	*get_next_line(int fd)
{
	static char	*sta;
	char		*sch;
	char		*line;

	sch = malloc(sizeof(char));
	if (!sch)
		return (free(sch), NULL);
	if (read(fd, sch, 0) == -1 || fd < 0 || BUFFER_SIZE <= 0)
		return (free(sch), NULL);
	*sch = 0;
	if (!sta)
	{
		sta = malloc(1);
		if (!sta)
			return (free(sta), NULL);
		*sta = '\0';
	}
	sch = ft_strjoin(sch, sta);
	free(sta);
	sch = ft_read_bytes(fd, sch);
	if (!sch)
		return (free(sch), NULL);
	line = ft_substr(sch, 0, ft_len_line(sch));
	sta = ft_substr(sch, ft_len_line(sch), (ft_strlen(sch) - ft_len_line(sch)));
	return (free(sch), line);
}
