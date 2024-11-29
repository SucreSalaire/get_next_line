#include "get_next_line.h"

int	main(int ac, char **av)
{
	int fd = open("file.txt", O_RDONLY);
	char *buffer;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	
	ssize_t cnt = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	
	int	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			break;
		i++;
	}
	char	*temp = ft_substr(buffer, 0, i);


	printf("buffer content: %s\n", buffer);
	printf("*temp content: %s\n", temp);
}


