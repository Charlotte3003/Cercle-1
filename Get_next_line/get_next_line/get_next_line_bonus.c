/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:27:37 by cbourre           #+#    #+#             */
/*   Updated: 2022/05/16 22:42:24 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*sta[1024];
	char		*sch;
	char		*line;

	sch = malloc(sizeof(char));
	if (!sch)
		return (free(sch), NULL);
	if (read(fd, sch, 0) == -1 || fd < 0 || BUFFER_SIZE <= 0)
		return (free(sch), NULL);
	*sch = 0;
	if (!sta[fd])
	{
		sta[fd] = malloc(1);
		if (!sta[fd])
			return (free(sta[fd]), NULL);
		*sta[fd] = '\0';
	}
	sch = ft_strjoin(sch, sta[fd]);
	free(sta[fd]);
	sch = ft_read_bytes(fd, sch);
	if (!sch)
		return (free(sch), NULL);
	line = ft_substr(sch, 0, ft_lline(sch));
	sta[fd] = ft_substr(sch, ft_lline(sch), (ft_strlen(sch) - ft_lline(sch)));
	return (free(sch), line);
}
