#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*mem_buf;
	char	*buf;
	char	*tmp_buf;
	ssize_t cnt;

	cnt = 0;
	if (mem_buf)
	{
		//if (get_prevline(mem_buf, buf)  == 0);
		//	return (buf);
		while (mem_buf[cnt])
			if (mem_buf[cnt++] == '\n')
				break;
		if (mem_buf[cnt] != 0)
		{
			buf = ft_substr(mem_buf, 0, cnt);
			mem_buf = ft_substr(mem_buf, cnt, ft_strlen(mem_buf) - cnt);
			return (buf);
		}
	}
	// cnt = get_buffer(fd, buf);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	cnt = read(fd, buf, BUFFER_SIZE);
	buf[cnt] = 0;
	cnt = 0;
	while (buf[cnt])
		if (buf[cnt++] == '\n')
			break;
	tmp_buf = ft_substr(buf, 0, cnt);
	tmp_buf = ft_strjoin(mem_buf, tmp_buf);
	mem_buf = ft_substr(buf, cnt, ft_strlen(buf) - cnt);
	return(tmp_buf);
}

int	main(int ac, char **av)
{
	int	fd = open("file.txt", O_RDONLY);
	char 	*ptr;
	int i = 0;

	while (i++ < av[1][0] - '0')
	{
		ptr = get_next_line(fd);
		printf("%s", ptr);
		free(ptr);
	}
}
