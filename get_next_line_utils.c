/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:44:29 by ygonzale          #+#    #+#             */
/*   Updated: 2022/05/20 13:28:08 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
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
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		n;

/* 	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	} */
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	n = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[n] != '\0')
		str[i++] = s2[n++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
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
** La funcion guarda suficiente memoria para copiar una string
** entonces la copia y te de vuelve la new string
**
** @param {const char *s} es la string que quieres copiar
**
** @return {char} La nueva string despues de copiar
*/
/* char	*ft_strdup(char *s1)
{
	int		i;
	int		count;
	char	*s2;

	count = 0;
	while (s1[count])
		count++;
	s2 = malloc(sizeof(char) * (count + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
 */