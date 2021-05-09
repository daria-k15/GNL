#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE 32
#include <unistd.h>
#include <stdlib.h>

int     get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin_free(char *s1, char *s2);
void	*ft_memmove(void *dst, const void *src, size_t n);
char		*ft_substr(char const *s, int start, int len);
#endif