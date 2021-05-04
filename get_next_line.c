#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(ft_strlen(s1) + 1);
	if (!dst)
		return ((void *)0);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}

/*char	ft_strchr(const char *str, int ch)
{
	while (*str != ch && *str != '\0')
		str++;
	if (*str == ch)
		return ((char *)str);
	return (0);
}*/

int get_next_line(int fd, char **line)
{
    char buf[BUFFER_SIZE + 1];
	int len;

	while ((len = read(fd, buf, BUFFER_SIZE)))
	{
		buf[len] = '\0';
		*line = ft_strjoin(*line, buf);
		
		
	}

    return (0);
}

int main()
{
    int fd;
    char    *buf;
    
    fd = open ("text.txt", O_RDONLY);
    get_next_line(fd, &buf);
    printf("%s", buf);
}
