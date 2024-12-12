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
//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c
#include "get_next_line.h"
#include <unistd.h>
#define BUFFER_SIZE 42

char *get_next_line(int fd)
{
    size_t i;
    static char buffer[BUFFER_SIZE];
    ssize_t bytes_read = 0;
    char *the_line = NULL;
    static size_t  old_len = 0;
    size_t  new_len = 0;
    size_t end_line_index = 0;

    if (BUFFER_SIZE <= 0 || fd < 0)
    {
        return (NULL);       
    }    
    
    old_len = ft_strlen(the_line);
    
    if (remaining_bytes > 0)
    {
        the_line = ft_realloc(the_line, old_len, new_len);
    }

    while(bytes_read = read(fd, buffer, BUFFER_SIZE) >0 )
    {   
        i = 0;    
       
        while(i < bytes_read)
        {            
            if(buffer[i] =='\n' )
            {
                new_len = old_len + i + 1;
                the_line = ft_realloc(the_line, old_len, new_len);
                bytes_processed = i + 1;
                remaining_bytes = bytes_read - bytes_processed;
               
                
            }            
            i++;
        }
                                       
    }
   
    if (bytes_read < 0)
        return(NULL);
    
    the_line[bytes_read] = '\0';
   
    return (the_line);
}
