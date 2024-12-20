int read_and_process(int fd, char **line, char *buffer, int *remaining_bytes, int *buffer_pos)
{
    ssize_t bytes_read;
    ssize_t new_line_index;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        new_line_index = find_char_index(buffer, '\n');
        if (new_line_index >= 0)
        {
            *line = ft_strjoin(*line, buffer, new_line_index + 1);
            if (!*line)
                return 1;
            *buffer_pos = new_line_index + 1;
            *remaining_bytes = bytes_read - new_line_index - 1;
            return 1;
        }
        else
        {
            *line = ft_strjoin(*line, buffer, bytes_read);
            if (!*line)
                return 1;
        }
    }
    return 0;
}
