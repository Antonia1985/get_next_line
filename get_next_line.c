#include "get_next_line.h"
#define BUFFER_SIZE 42

int	process_remaining_bytes(char *buffer, char **the_line, int *buffer_pos)
{
	ssize_t	new_line_index;
	int		remaining_bytes;

	if (*buffer_pos > 0)
	{
		new_line_index = find_char_index(&buffer[*buffer_pos], '\n');
		if (new_line_index >= 0)
		{
			*the_line = ft_strjoin(*the_line, &buffer[*buffer_pos], new_line_index + 1);
			if (!*the_line)
				return (1);
			*buffer_pos += new_line_index + 1;
			return (1);
		}
		else
		{
			remaining_bytes = ft_strlen(&buffer[*buffer_pos]);
			*the_line = ft_strjoin(*the_line, &buffer[*buffer_pos], remaining_bytes);
			if (!*the_line)
				return (1);
			*buffer_pos = 0;
		}
	}
	return (0);
}

int	error_handling(ssize_t bytes_read, char **the_line)
{
	if (bytes_read < 0)
	{
		free(*the_line);
		*the_line = NULL;
		return (1);
	}
	return (0);
}

int	read_and_append(int fd, char *buffer, char **the_line, int *buffer_pos)
{
	ssize_t	bytes_read;
	ssize_t	new_line_index;

	bytes_read = 0;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		new_line_index = find_char_index(buffer, '\n');
		if (new_line_index >= 0)
		{
			*the_line = ft_strjoin(*the_line, buffer, new_line_index + 1);
			if (!*the_line)
				return (1);
			*buffer_pos = new_line_index + 1;
			return (1);
		}
		else
		{
			*the_line = ft_strjoin(*the_line, buffer, bytes_read);
			if (!*the_line)
				return (1);
		}
	}
	return (error_handling(bytes_read, the_line));
}

char	*handle_eof_case_and_return_line(char **the_line, int *buffer_pos, char *buffer)
{
	size_t	buff_len;

	if (*buffer_pos > 0)
	{
		buff_len = ft_strlen(buffer) - *buffer_pos + 1;
		*the_line = ft_strjoin(*the_line, buffer, buff_len);
		if (!*the_line)
			return (NULL);
		*buffer_pos = 0;
		return (*the_line);
	}
	if ((*the_line)[0] != '\0')
		return (*the_line);
	free(*the_line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int	buffer_pos;
	char		*the_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	the_line = malloc(BUFFER_SIZE + 1);
	if (!the_line)
		return (NULL);
	the_line[0] = '\0';
	if (process_remaining_bytes(buffer, &the_line, &buffer_pos))
		return (the_line);
	if (read_and_append(fd, buffer, &the_line, &buffer_pos))
		return (the_line);
	the_line = handle_eof_case_and_return_line(&the_line, &buffer_pos, buffer);
	return (the_line);
}
