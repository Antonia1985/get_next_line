char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    static int remaining_bytes = 0;
    static int buffer_pos = 0;
    
    read_file();
    if (bytes_read)
     return (the_line);
    the_line = handle_final_cases(&the_line, &buffer_pos, &remaining_bytes, &bytes_read);
    return (the_line);
}

void read_file(int fd, &buffer, int *buffer_pos, int *remaining_bytes)
{
    ssize_t bytes_read;
    ssize_t new_line_index;

    while((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0 )
	{
		buffer[bytes_read] = '\0';
        new_line_index = find_char_index(buffer, '\n');
        if(new_line_index >= 0)//found NEW LINE
        {
            the_line = ft_strjoin(the_line, buffer, new_line_index + 1);
            if (!the_line)
            return (NULL);         
            buffer_pos = new_line_index + 1;
            remaining_bytes = bytes_read - (new_line_index + 1);
            break;
        }
        else
        {
            the_line = ft_strjoin(the_line, buffer, bytes_read);
            if (!the_line)
            return (NULL);
        }
	}  
    return (the_line);
}

char *handle_final_cases(char **line, int *buffer_pos, int *remaining_bytes, ssize_t *bytes_read)
{
    if (bytes_read == 0)
    {
        if ((*the_line[0]) != '\0')
        {
            buffer_pos = 0;
            remaining_bytes = 0;
            return (the_line);
        }
        // If no line is found, free the allocated memory and return NULL
        free(*the_line);
        return (NULL);    
    }
    if (bytes_read < 0)
    {
        free(*the_line);
        return (NULL); 
    }
    return (*the_line);
}

