#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 3
#include <unistd.h>
#include <stdlib.h>

int     get_next_line(int fd, char **line);
size_t  ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int ch);


#endif