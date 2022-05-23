/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:36:52 by ygonzale          #+#    #+#             */
/*   Updated: 2022/05/23 10:19:11 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *bufread);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		line_jump(char *savebuf);
char	*ft_strdup(char *s1);
char	*ft_substr_line(char *savebuf);
char	*ft_substr_static(char *s);

#endif