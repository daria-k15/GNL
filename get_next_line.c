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


int main()
{
    int     fd;
    char    *line;
    fd = open ("alphabet", O_RDONLY);
    while (get_next_line(fd, &line))
        printf("%s\n", line);
    return (0);
}

