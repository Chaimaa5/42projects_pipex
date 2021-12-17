#ifndef PIPEX_H
#define PIPEX_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
char    *search(char **path, char *cmd);

#endif