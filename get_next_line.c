/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 02:27:31 by cperales          #+#    #+#             */
/*   Updated: 2024/12/30 10:48:58 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_remainder(char *remainder)
{
    int i = 0;
    int j = 0;
    int len = ft_strlen(remainder);
    char *line;

    while (remainder[i] && remainder[i] != '\n')
        i++;
    
    if (!remainder[i]) {
        free(remainder);
        return (NULL);
    }

    line = malloc(sizeof(char) * ((len - i) + 1));
    if (!line)
        return (NULL);

    i++;
    while (remainder[i])
        line[j++] = remainder[i++];
    line[j] = '\0';

    free(remainder);
    return (line);
}

char *fd_reader(int fd, char *remainder)
{
    char *buf;
    int byte_read;

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buf == NULL)
        return (NULL);

    buf[0] = '\0';
    byte_read = 1;

    while (!(ft_strchr(buf, '\n')) && byte_read) {
        byte_read = read(fd, buf, BUFFER_SIZE);
        if (byte_read == -1) {
            free(buf);
            return (NULL);
        }
        buf[byte_read] = '\0';
        remainder = ft_strjoin(remainder, buf);
        if (!remainder) {
            free(buf);
            return (NULL);
        }
    }

    free(buf);
    return (remainder);
}

char *get_next_line(int fd)
{
    static char *remainder;
    char *line = NULL;
    int i = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    remainder = fd_reader(fd, remainder);
    if (!remainder)
        return (NULL);

    if (*remainder) {
        while (remainder[i] && remainder[i] != '\n')
            i++;

        line = malloc(sizeof(char) * (i + 2));
        if (!line) {
            free(remainder);
            return (NULL);
        }
        line = ft_strcpy(line, remainder);
    }

    remainder = ft_remainder(remainder);
    return (line);
}
