#ifndef GET_NEXT_LINE_H

#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 42  // Default value if not specified at compile time
#endif

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	populate_joined(char *joined, char *s, size_t s_len, size_t start);
char	*ft_strjoin(char *s1, char *s2, size_t s2_len);
char    *get_next_line(int fd);
int find_char_index(const char *str, char ch);
int  update_buf_position(ssize_t new_line_index);
int  update_remaining_bytes(int new_line_index, ssize_t bytes_read);
int main(int argc, char **argv);

#endif