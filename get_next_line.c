#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"




int	ft_index(const char *str, int ch)
{
    size_t   i;

    i = 0;
	while (str[i] != ch && str[i])
		i++;
	if (str[i] != (char)ch)
		return (-1);
	return (i);
}

int get_line(char **line, char *buf, int i)
{
    *line = ft_substr(buf, 0, i);
    ++i;
    ft_memmove(buf, buf + i, (ft_strlen(buf + i) + 1));
    return(1);
}
int get_next_line(int fd, char **line)
{
    static char    *buf;
    char    tmp[BUFFER_SIZE + 1];
    int     i;
    int     bytes;
   
    if (fd < 0 || !line || read(fd, 0, 0) < 0 || BUFFER_SIZE < 0)
        return (-1);
    if (buf && (i = ft_index(buf, '\n')) != -1)
        return (get_line(line, buf, i));      
    while ((bytes = read(fd, tmp, BUFFER_SIZE)))
    {
        tmp[bytes] = '\0';
        buf = ft_strjoin_free(buf, tmp);
        if ((i = ft_index(buf, '\n')) != -1)
            return (get_line(line, buf, i));
    }
    if (buf)
    {
        *line = ft_strdup(buf);
        free(buf);
        buf = NULL;
        return (bytes);
    }
    else 
        *line = ft_strdup("");
    return (bytes);
    }


/*int main()
{
    int fd;
  //  char *buf;
    char *line;

    fd = open("text.txt", O_RDONLY);
    while (get_next_line(fd, &line))
    {
        printf("|%s\n", line);
    }

}*/

/*int main()
{
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;
	char			*lineadress[66];
	
	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("text.txt", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 66)
		printf("\nRight number of lines\n");
	else if (j != 66)
		printf("\nNot Good - Wrong Number Of Lines\n");
	while (--j > 0)
		free(lineadress[j - 1]);
	j = 1;
}*/