#include "get_next_line.h"
#define BUFFER_SIZE 42

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

void	populate_joined(char *joined, char *s, size_t s_len, size_t start)
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
	char	*joined;

	if (s1 == NULL)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	len = len1 + s2_len + 1;
	joined = (char *)malloc(len);
	if (!joined)
		return (NULL);
	populate_joined(joined, s1, len1, 0);
	populate_joined(joined, s2, s2_len, len1);
	joined[len - 1] = '\0';
	if (s1)
		free(s1);
	return (joined);
}

int	find_char_index(const char *str, char ch)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}