/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:36:30 by ygonzale          #+#    #+#             */
/*   Updated: 2022/05/17 13:10:25 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *savebuf)
{
	ssize_t	nr_bytes;
	char	*buf;

	nr_bytes = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(savebuf, '\n'))
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		if (nr_bytes < 0)
		{
			free (buf);
			return (NULL);
		}
		if (nr_bytes == 0)
			break ;
		buf[nr_bytes] = '\0';
		savebuf = ft_strjoin(savebuf, buf);
	}
	free(buf);
	return (savebuf);
}

int	read_line(char *savebuf)
{
	int		i;

	i = 0;
	while (savebuf[i])
	{
		if (savebuf[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_substr_line(char *savebuf)
{
	char	*str;
	size_t	i;

	if (!savebuf)
		return (NULL);
	str = (char *)malloc(sizeof(savebuf) * (read_line(savebuf) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (savebuf[i] && savebuf[i] != '\n')
	{
		str[i] = savebuf[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr_static(char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = read_line(s);
	j = 0;
	if (!s)
		return (s);
	str = (char *)malloc(sizeof(s) * (ft_strlen(s) - read_line(s)));
	if (!str)
		return (NULL);
	i++;
	while (s[i] && s[i] != '\n')
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*savebuf;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!savebuf)
		savebuf = ft_strdup("");
	savebuf = ft_read(fd, savebuf);
	if (!savebuf)
		return (NULL);
	line = ft_substr_line(savebuf);
	savebuf = ft_substr_static(savebuf);
	free (savebuf);
	return (line);
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
