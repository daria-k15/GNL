#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"


static int	index_search(const char *str, int ch)
{
    size_t   i;

    i = 0;
	while (str[i] != ch && str[i])
		i++;
	if (str[i] != (char)ch)
		return (-1);
	return (i);
}

static int get_line(char **line, char *buf, int i)
{
    *line = ft_substr(buf, 0, i);
    ++i;
    ft_memcpy(buf, buf + i, (ft_strlen(buf + i) + 1));
    return(1);
}
int get_next_line(int fd, char **line)
{
    static char    *buf[OPEN_MAX];
    char    tmp[BUFFER_SIZE + 1];
    int     i;
    int     bytes;
   
    if (fd < 0 || !line || read(fd, 0, 0) < 0 || BUFFER_SIZE < 0)
        return (-1);
    if (buf[fd] && (i = index_search(buf[fd], '\n')) != -1)
        return (get_line(line, buf[fd], i));      
    while ((bytes = read(fd, tmp, BUFFER_SIZE)) > 0)
    {
        tmp[bytes] = '\0';
        buf[fd] = ft_strjoin_free(buf[fd], tmp);
        if ((i = index_search(buf[fd], '\n')) != -1)
            return (get_line(line, buf[fd], i));
    }
    if (buf[fd])
    {
        *line = ft_strdup(buf[fd]);
        free(buf[fd]);
        buf[fd] = NULL;
        return (bytes);
    } 
    *line = ft_strdup("");
    return (bytes);
}


/*int main()
{
    int             fd;
    int     fd2;
	int             i;
	int             j;
	char    *line;

    j = 0;



	if (!(fd = open("mix_marge1", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	if (!(fd2 = open("mix_marge2", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while (j < 8)
	{
		if ((i = get_next_line(fd, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	while (j < 13)
	{
		if ((i = get_next_line(fd2, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	if ((i = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd2, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd2, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd2, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	while (j < 23)
	{
		if ((i = get_next_line(fd2, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);
	j++;
	while (j < 25)
	{
		if ((i = get_next_line(fd, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	close(fd);
	close(fd2);
}*/