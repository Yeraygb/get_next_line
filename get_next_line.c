/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:36:30 by ygonzale          #+#    #+#             */
/*   Updated: 2022/05/09 15:38:41 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_read(int fd, char *buf)
{
	ssize_t	nr_bytes;

	nr_bytes = read(fd, buf, BUFFER_SIZE);
	if (nr_bytes < 0)
		return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*read;
	static char	*bufread;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read = ft_read(fd, buf);
}
