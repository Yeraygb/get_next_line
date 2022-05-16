/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:44:29 by ygonzale          #+#    #+#             */
/*   Updated: 2022/05/16 12:30:49 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

/*
** Reserva y devuelve una nueva string,
** formada por la concatenación de ’s1’ y ’s2’.
**
** @param {char const s1} Primera string
** @param {char const s2} Segunda string
** 
** @return {char *} La string concatenada resultante
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[len_s1++] = s2[i++];
	}
	str[len_s1] = '\0';
	return (str);
}

/*
** Funcion busca el primer caracter que coincide en 2 strings
**
** @param {const char *s} La string en la que se quiere buscar un parametro
** @param {int c} El parametro que quieres buscar
**
** @return {char} La direc de la *s desde que ha encontrado la 1º coincidencia
*/
char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[i]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

/*
** La funcion reserva memoria para crear una suybstring empezando por start
** y tiene una longitud max
**
** @param {char const *s} La string que quieres copiar
** @param {unsigned int start} El indice start por el que quieres que empieze a
** copiar
** @param {size_t len} El tamaño que quieres copiar
**
** @return {char} La nueva substring
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
