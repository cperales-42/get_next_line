#include "get_next_line.h"
#include <stdio.h>

char	*ft_get_next_line(int fd)
{
	static char buffer[1024];
	size_t			i;
	static size_t		j = 0;
	char	*line;
	size_t	bytesRead;

	if (fd == (-1))
		return (NULL);
	i = 0;
	bytesRead = 0;
	line = malloc(1024);					//creo que esto debería de ser un calloc (o un bzero)
	if (!line)
		return (NULL);
	if (j == 0)
	{
		if (fd == (-1))
			return (NULL);
		bytesRead = read(fd, buffer, sizeof(buffer));
		if (bytesRead <= 0)
			return (NULL);
	}
	while (buffer[j] != '\n' && j < bytesRead)
	{
		line[i] = buffer[j];
		i++;
		j++;
	}
	if (j >= bytesRead)
		return (NULL);
	if (buffer[j] == '\n')
		j++;
	line[i] = '\0';
	return (line);
}

int main(void)
{
	int	fd;
	char	*fileName;

	fileName = "hello.txt";
	fd = open(fileName, O_RDWR);

	printf("%s\n", ft_get_next_line(fd));
	printf("%s\n", ft_get_next_line(fd));
	//printf("%s\n", ft_get_next_line(fd));
	//printf("%s\n", ft_get_next_line(fd));
	//printf("%s\n", ft_get_next_line(fd));
	//printf("%s\n", ft_get_next_line(fd));
	//printf("%s\n", ft_get_next_line(fd));
	//printf("%s\n", ft_get_next_line(fd));
	//printf("%s\n", ft_get_next_line(fd));
}
