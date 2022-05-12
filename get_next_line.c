/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:36:30 by ygonzale          #+#    #+#             */
/*   Updated: 2022/05/12 15:04:31 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buf, char *savebuf)
{
	ssize_t	nr_bytes;

	while (!ft_strchr(savebuf, '\n'))
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		if (nr_bytes < 0)
			return (NULL);
		savebuf = ft_strjoin(savebuf, buf);
		free(buf);
	}
	return (savebuf);
}


char	*get_next_line(int fd)
{
	char		*buf;
	char		*read;
	static char	*savebuf;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	savebuf = ft_read(fd, buf, savebuf);
	if (!savebuf)
		return (NULL); 
	read = ft_substr(savebuf, 0, read_line(savebuf));
	return(read);
}

size_t	read_line(char *savebuf)
{
	char	*line;
	int		i;

	i = 0;
	while (savebuf[i])
	{
		if (ft_strchr(savebuf, '\n'))
			return (i);
		i++;
	}
	return (0);
}

/* 	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL); */

int main()
{
	ssize_t	fd = open("test1.txt", O_RDONLY);
	size_t	i = 4;
	char	*line;

	while (i--)
	{
		line = get_next_line(fd);
		printf("line %zu = %s\n", i, line);
		free(line);
	}
	close(fd);
	return (0);
}
