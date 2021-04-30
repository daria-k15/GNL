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

int get_next_line(int fd, char **line)
{
    char buf[BUFFER_SIZE + 1];

    read(fd,buf, BUFFER_SIZE);
    buf[BUFFER_SIZE] = '\0';
    *line = ft_strdup(buf);

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
