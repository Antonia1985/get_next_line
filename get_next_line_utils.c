#include "get_next_line.h"

/*size_t last_bytes_read(size_t bytes_read, size_t BUFFER_SIZE)
{
    size_t quotient = bytes_read / BUFFER_SIZE;
    size_t remaining = bytes_read % BUFFER_SIZE;

    if (quotient == 0 && remaining == 0)
        return (0);
    else if(quotient > 0 && remaining == 0)
        return (BUFFER_SIZE); 
    else
        return(remaining);
}*/

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

ft_realloc(char * line, const char *buffer, size_t buffer_size)
{
   
    if (line)
    {
        size_t  old_len;
        old_len = ft_strlen(line);

    }
}