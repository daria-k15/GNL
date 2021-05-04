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
    unsigned char *src1;

    i = 0;
    src1 = (unsigned char *)src;
    while (src1[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

char    *check_rem(char *rem, char **line)
{
    char    *point;

    point = NULL;
    if (rem)
    {
        if ((point = ft_strchr(rem, '\n')))
        {
            *point = '\0';
            *line = ft_strdup(rem);
            ft_strcpy(rem, ++point);
        }
        else
        {
            *line = ft_strdup(rem);
            ft_strclr(rem);
        }
    } 
    else
        *line = ft_memalloc(1);
    return (point);
}

int get_line(int fd, char **line)
{
    char buf[BUFFER_SIZE + 1];
	int len;
    char *point;
    static char *rem;
    char *tmp;

    point = NULL;
    check_rem(rem, line);
	while (!point && (len = read(fd, buf, BUFFER_SIZE)))
	{
        buf[len] = '\0';
        if ((point = ft_strchr(buf, '\n')))
        {
            *point = '\0';
            rem = ft_strdup(++point);
        }
        tmp = *line;
		*line = ft_strjoin(tmp, buf);
        free(tmp);
	}
    return (0);
}

int get_next_line(int fd, char **line)
{
    int     bytes;
    char    buf[BUFFER_SIZE + 1];

    if (fd < 0 || !line || (read(fd, buf, BUFFER_SIZE)) < 0)
        return (-1);
    while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[bytes] = '\0';
    }
    return (0);
}


int main()
{
    int     fd;
    char    *line;
    //int     i = 0;
    fd = open ("text.txt", O_RDONLY);

    get_line(fd, &line);
    printf("%s\n", line);
    get_line(fd, &line);
    printf("%s\n", line);
    get_line(fd, &line);
    printf("%s\n", line);
    /*while (get_next_line(fd, &line) > 0)
    {
        printf("1");
        printf("i = %d %s\n", i, line);
        i++;
    }*/
    
    return (0);
}
