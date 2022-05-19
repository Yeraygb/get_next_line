/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:25:32 by marvin            #+#    #+#             */
/*   Updated: 2022/05/18 19:25:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prueba.h"

char	*ft_read_buffer(int fd, char *savebuf)
{
	ssize_t nr_bytes;
	char	*buf;

	nr_bytes = 1;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	while (!ft_strchr(savebuf, '\n'))
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		if (nr_bytes == -1)
		{
			free (buf);
			return (NULL);
		}
		savebuf = ft_strjoin(savebuf, buf);
	}
	free (buf);
	return (savebuf);
}

char	*ft_save_line(char *savebuf)
{
	char 	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!savebuf)
		return (NULL);
	while (savebuf[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (savebuf[j] != '\n' && savebuf[j])
	{
		str[j] = savebuf[j];
		j++;
	}
/* 	if (savebuf[j] == '\n')
	{
		str[j] = savebuf[j];
		j++;
	} */
	str[j] = '\0';
	return (str);
}

char	*ft_save_static(char *savebuf)
{
	char 	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!savebuf)
		return (NULL);
	while (savebuf[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(savebuf) - i) + 1);
	if (!str)
	{
		free (savebuf);
		return (NULL);
	}
	j = 0;
	while (savebuf[i])
	{
		str[j] = savebuf[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free (savebuf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char *savebuf;
	char		*line;

	if (fd < 1 || BUFFER_SIZE < 0)
		return (NULL);
	savebuf = ft_read_buffer(fd, savebuf);
	line = ft_save_line(savebuf);
	savebuf = ft_save_static(savebuf);
	return (line);
}

int main()
{
	ssize_t	fd = open("test1.txt", O_RDONLY);
	size_t	i = 3;
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
