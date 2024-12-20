#include "get_next_line.h"

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

void	populate_joined(char *joined, char *s, size_t s_len,
		size_t start)
{
	size_t	j;

	j = 0;
	if (s != NULL)
	{
		while (j < s_len)
		{
			joined[start + j] = s[j];
			j++;
		}
	}	
}

char	*ft_strjoin(char *s1, char *s2, size_t s2_len)
{
	size_t	len1;
	size_t	len;
	
	if (s1 == NULL)
		len1 = 0;
    else
    {
        len1 = ft_strlen(s1);
    }
   
	len = len1 + s2_len + 1;
    char	*joined = (char *)malloc(len);
    if (!joined)
    return (NULL);

	populate_joined(joined, s1, len1, 0);
	populate_joined(joined, s2, s2_len, len1);

	joined[len - 1] = '\0';
	if (s1)
	    free(s1);

	return (joined);
}

int find_char_index(const char *str, char ch) 
{
    //sos str must be null terminated
	size_t	i = 0;
	
	while (str[i] != '\0')
	{
		if (str[i] == ch)
		    return (i);
        i++;
    }
    return (-1); // Character not found
}

int  update_buf_position(ssize_t new_line_index)
{	
	int buffer_pos;

	buffer_pos = 0;
	if(new_line_index >= 0)//found NEW LINE
	{
		buffer_pos = new_line_index + 1;		
	}
	else // contains NO NEW LINE (-1)
    {
		buffer_pos = 0;				
	}
	return(buffer_pos);
}

int update_remaining_bytes(int new_line_index, ssize_t bytes_read)
{
	int remaining_bytes;

	remaining_bytes = 0;
	if(new_line_index >= 0)//found NEW LINE
	{
		remaining_bytes = bytes_read - (new_line_index + 1);
	}
	else // contains NO NEW LINE (-1)
    {
		remaining_bytes = 0;
	}
	return(remaining_bytes);
}
