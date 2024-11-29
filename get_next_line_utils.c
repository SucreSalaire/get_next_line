/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:13:36 by salmou            #+#    #+#             */
/*   Updated: 2024/11/29 12:13:40 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	get_nextstate(char c, char c_case)
{
	if (c_case == 0)
	{
		if (c == '\n')
			return (2);
		else
			return (1);
	}
	if (c)
		return (4);
	else
		return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if ((ft_strlen(s) - start < len))
		len = ft_strlen(s) - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr[len] = 0;
	if (len > 0)
		while (len--)
			ptr[len] = s[start + len];
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!ptr)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[j])
		{
			ptr[i + j] = s2[j];
			j++;
		}
	}
	free(s1);
	free(s2);
	ptr[i + j] = 0;
	return (ptr);
}

size_t	get_endline(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] != '\n' && buf[i] && i < BUFFER_SIZE)
		i++;
	return (i);
}

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
    if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
