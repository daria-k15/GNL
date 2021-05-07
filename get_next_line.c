#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void    *ft_memalloc(size_t size)
{
    char    *new;

    if (!(new = (char *)malloc(size + 1)))
        return (NULL);
    while (size-- > 0)
        new[size] = '\0';
    new[size] = '\0';
    return ((void *)new);
}

void    ft_strclr(char *s)
{
    if (s != NULL)
    {
        while (*s)
        {
            *s = '\0';
            s++;
        }
    }
}

char    *ft_strcpy(char *dst, const char *src)
{
    size_t  i;

    i = 0;
    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}
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

char	*ft_strchr(const char *str, int ch)
{
	while (*str != ch && *str != '\0')
		str++;
	if (*str == ch)
		return ((char *)str);
	return (0);
}


/*int get_line(int fd, char **line)
{
    char buf[BUFFER_SIZE + 1];
	int len;
    char *point;
    static char *ost;
    char *tmp;

    point = NULL;
    check_ost(ost, line);
	while (!point && (len = read(fd, buf, BUFFER_SIZE)))
	{
        buf[len] = '\0';
        if ((point = ft_strchr(buf, '\n')))
        {
            *point = '\0';
            ost = ft_strdup(++point);
        }
        tmp = *line;
		*line = ft_strjoin(*line, buf);
        free(tmp);
	}
    return (0);
}*/
char     *check_ost(char *ost, char **line)
{
    char *point;

    point = NULL;
    if (ost)
    {
        if ((point = ft_strchr(ost, '\n')))
        {
            *point = '\0';
            *line = ft_strdup(ost);
            ft_strcpy(ost, ++point);
        }
        else
        {
            *line = ft_strdup(ost);
            ft_strclr(ost);
        }
    }
    else
        *line = ft_memalloc(1);
    return (point);
}
int get_next_line(int fd, char **line)
{
    int     bytes;
    char    *buf;
    char    *point;
    static char    *ost;
    char *tmp;
 
    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    if (!(buf = (char *) malloc(sizeof(char *) * (BUFFER_SIZE + 1))))
        return (-1);
    point = check_ost(ost, line);
    while (!point && (bytes = read(fd, buf, BUFFER_SIZE)))
    {
        buf[bytes] = '\0';
        if ((point = ft_strchr(buf, '\n')))
        {
            *point = '\0';
            ost = ft_strdup(++point);
        }
        tmp = *line;
		*line = ft_strjoin(*line, buf);
        free(tmp);

    }
    return ((bytes || ft_strlen(ost)) ? 1: 0);
}


/*int main()
{
    int     fd;
    char    *line;
    fd = open ("text.txt", O_RDONLY);
    while (get_next_line(fd, &line))
        printf("%s\n", line);
    return (0);
}*/
