#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>   
# include <stdlib.h>
size_t	ft_strlen(const char *str);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
char	*ft_strjoinf(char *s1, char *s2);
char	*ft_substr(char const *s, int start, int len);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif