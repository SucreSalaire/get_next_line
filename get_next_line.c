/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:44:23 by salmou            #+#    #+#             */
/*   Updated: 2024/11/29 14:29:23 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_free(char *buf, char *s_buf, size_t end, char flag)
{
	if (end <= 0 && (flag == 0 || flag == 1))
	{
		if (buf)
			free(buf);
		if (s_buf)
			free(s_buf);
		return (0);
	}
	if (flag == 2)
	{
		if (buf)
			free(buf);
	}
	return (flag);
}

char	*get_next_line(int fd)
{
	static struct t_state	state;
	char					*buf;
	char					*tmp_buf;
	ssize_t					end;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	if (state.flag == 0 || state.flag == 1)
	{
		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		end = read(fd, buf, BUFFER_SIZE);
		state.flag = ft_free(buf, state.buf, end, state.flag);
		if (end <= 0)
			return (NULL);
		buf[end] = 0;
	}
	if (state.flag == 4)
		buf = ft_substr(state.buf, 0, ft_strlen(state.buf));
	end = get_endline(buf);
	state.flag = get_nextstate(buf[end], 0);
	if (state.flag == 1)
		tmp_buf = ft_strjoin(buf, get_next_line(fd));
	if (state.flag == 2)
	{
		state.buf = ft_substr(buf, end + 1, ft_strlen(buf) - end);
		tmp_buf = ft_substr(buf, 0, end);
		state.flag = get_nextstate(state.buf[0], 1);
		ft_free(buf, state.buf, 1, 2);
	}
	return (tmp_buf);
}

int	main(int ac, char **av)
{
	int		fd = open("file.txt", O_RDONLY);
	char	*ptr;
	int		i = 0;
	if (ac)
	{
		while (i++ < ft_atoi(av[1]))
		{
			ptr = get_next_line(fd);
			if (ptr)
			{
				printf("%s\n", ptr);
				free(ptr);
			}
		}
	}
	return (0);
}
