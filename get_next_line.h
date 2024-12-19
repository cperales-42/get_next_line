
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
char	*get_next_line(int fd);
int	open_line(int fd, size_t bytesRead, char *buffer);
#endif
