#ifndef UTIL_H
# define UTIL_H

# include <string.h>

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_getenv(char **envp, const char *name);
size_t	ft_strlen(const char *s);

#endif
