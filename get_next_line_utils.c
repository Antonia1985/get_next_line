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

static void	populate_joined(char *joined, char *s, size_t s_len,
		size_t start)
{
	size_t	j;

	j = 0;
	while (j < s_len)
	{
		joined[start + j] = s[j];
		j++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	len;
	char	*joined;

	if (s1 == NULL)
		len1 = 0;
	if (s2 == NULL)
		len2 = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2 + 1;
	joined = (char *)malloc(len);
	if (!joined)
		return (NULL);
	populate_joined(joined, s1, len1, 0);
	populate_joined(joined, s2, len2, len1);
	joined[len - 1] = '\0';
    free(s1);
	return (joined);
}