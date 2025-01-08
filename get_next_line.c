/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 02:27:31 by cperales          #+#    #+#             */
/*   Updated: 2025/01/08 23:58:00 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str_line)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (str_line[i] != '\0' && str_line[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i + 1)
	{
		line[j] = str_line[j];
		j++;
	}
	return (line);
}

char	*ft_read(int fd, char *str_buff)
{
	char	*buf;
	int		bytes_read;

	bytes_read = BUFFER_SIZE;
	while (bytes_read > 0 && !ft_strchr(str_buff, '\n'))
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
			return (NULL);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= -1)
			return (free(buf), free(str_buff), NULL);
		if (bytes_read == 0)
		{
			if (str_buff)
				return (free(buf), str_buff);
			else
				return (free(buf), NULL);
		}
		str_buff = ft_str_join_and_free(str_buff, buf);
	}
	return (str_buff);
}

char	*ft_next(char *buf)
{
	char	*remainder;
	int		j;
	int		i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	i++;
	if (ft_strlen(buf) == i)
		return (free(buf), NULL);
	remainder = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	if (!remainder)
		return (NULL);
	j = 0;
	while (buf[i])
		remainder[j++] = buf[i++];
	free(buf);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read(fd, buf);
	if (!buf)
		return (NULL);
	line = ft_get_line(buf);
	buf = ft_next(buf);
	return (line);
}

/*int main(void)
{
    #include <stdio.h>
    int fd = open("hello.txt", O_RDONLY);

    char *line = get_next_line(fd);

    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);
}*/
