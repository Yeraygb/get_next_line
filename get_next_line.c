/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:36:30 by ygonzale          #+#    #+#             */
/*   Updated: 2022/05/18 13:37:15 by ygonzale         ###   ########.fr       */
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
	while (!ft_strchr(savebuf, '\n') && nr_bytes != 0)
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		if (nr_bytes == -1)
		{
			free (buf);
			free (savebuf);
			return (NULL);
		}
		if (nr_bytes == 0)
			break ;
		buf[nr_bytes] = '\0';
		savebuf = ft_strjoin(savebuf, buf);
	}
	free (buf);
	return (savebuf);
}

int	line_jump(char *savebuf)
{
	int		i;

	i = 0;
	while (savebuf[i])
	{
		if (savebuf[i] == '\n')
			return (++i);
		i++;
	}
	return (i);
}

char	*ft_substr_line(char *savebuf)
{
	char	*str;
	size_t	i;
	size_t	n;

	n = 0;
	if (!savebuf)
		return (NULL);
	while (savebuf[n] && savebuf[n] != '\n')
		n++;
	str = (char *)malloc(sizeof(char) * (line_jump(savebuf) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (savebuf[i] && savebuf[i] != '\n')
	{
		str[i] = savebuf[i];
		i++;
	}
	if (savebuf[i] == '\n')
		str[i] = savebuf[i];
	str[i] = '\0';
	return (str);
}

char	*ft_substr_static(char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = line_jump(s);
	j = 0;
	if (!s)
	{
		free (s);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!str)
		return (NULL);
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	free (s);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*savebuf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	savebuf = ft_read(fd, savebuf);
	if (!savebuf)
	{
		free (savebuf);
		return (NULL);
	}
	line = ft_substr_line(savebuf);
	savebuf = ft_substr_static(savebuf);
	return (line);
}

int main()
{
	ssize_t	fd = open("test1.txt", O_RDONLY);
	size_t	i = 5;
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
