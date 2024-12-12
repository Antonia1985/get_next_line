#ifndef GET_NEXT_LINE_H

#define GET_NEXT_LINE_H
#define BUFFER_SIZE 42
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char *get_next_line(int fd);
int main(int argc, char **argv);

#endif