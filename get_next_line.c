#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

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
	dst = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
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

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	free (s1);
	s1 = NULL;
	j = 0;
	while (s2[j] != '\0')
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
char		*ft_substr(char const *s, int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	index_search(const char *str, int ch)
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
    ft_memcpy(buf, buf + i, (ft_strlen(buf + i) + 1));
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
    if (buf && (i = index_search(buf, '\n')) != -1)
        return (get_line(line, buf, i));      
    while ((bytes = read(fd, tmp, BUFFER_SIZE)) > 0)
    {
        tmp[bytes] = '\0';
        buf = ft_strjoinf(buf, tmp);
        if ((i = index_search(buf, '\n')) != -1)
            return (get_line(line, buf, i));
    }
    if (buf)
    {
        *line = ft_strdup(buf);
        free(buf);
        buf = NULL;
        return (bytes);
    }
    *line = ft_strdup("");
    return (bytes);
}


int main()
{
    int fd;
  //  char *buf;
    char *line;

    fd = open("text.txt", O_RDONLY);
    while (get_next_line(fd, &line))
    {
        printf("|%s\n", line);
    }
    printf("|%s", line);

}

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