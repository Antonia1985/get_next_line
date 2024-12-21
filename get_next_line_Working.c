/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:26:09 by apavlopo          #+#    #+#             */
/*   Updated: 2024/12/08 13:26:16 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
///cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c
#include "get_next_line.h"
#define BUFFER_SIZE 42

char *get_next_line(int fd)
{    
    static char buffer[BUFFER_SIZE + 1];          
    static int  remaining_bytes;   
    static int  buffer_pos;    
    char    *the_line;
    ssize_t bytes_read;
    ssize_t new_line_index;

    new_line_index = 0;
    bytes_read = 0;
    the_line = malloc(BUFFER_SIZE + 1);
    if (!the_line)
        return (NULL);
    the_line[0] = '\0';

    if (BUFFER_SIZE <= 0 || fd < 0)
    return (NULL);
    
    if (remaining_bytes > 0)
    {   
        //ssize_t first_new_line_index = find_char_index(buffer, '\n');
        //buffer_pos = first_new_line_index + 1;
        new_line_index = find_char_index(&buffer[buffer_pos], '\n');
        if(new_line_index >= 0)//found NEW LINE
        {
            the_line = ft_strjoin(the_line, &buffer[buffer_pos], new_line_index+1);
            if (!the_line)
                return (NULL);
            buffer_pos += new_line_index + 1; // Move buffer_pos to the next character
            remaining_bytes -= new_line_index + 1; // Reduce remaining bytes
            return(the_line);
        }
        else // No NEW LINE found
        {
            the_line = ft_strjoin(the_line, &buffer[buffer_pos], remaining_bytes);
            if (!the_line)
                return (NULL);
            buffer_pos = 0; // Reset buffer_pos
            remaining_bytes = 0; // Clear remaining_bytes
        }
    }
	
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
            buffer_pos = 0;
            remaining_bytes = 0;
        }
	}
	
    if (bytes_read == 0)
    {
        if (the_line[0] != '\0')
        {
            buffer_pos = 0;
            remaining_bytes = 0;
            return (the_line);
        }
        // If no line is found, free the allocated memory and return NULL
        free(the_line);
        return (NULL);    
    }

    if (bytes_read < 0)
    {
        free(the_line);
        return (NULL); 
    }
    return (the_line);
}