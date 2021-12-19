#ifndef PIPEX_H
#define PIPEX_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
char    *search(char **path, char *cmd);
size_t	ft_strlen(const char	*str);
char    *search(char **path, char *cmd);
char	**ft_split_path(char const *s, char c, char *path);
void	ft_putstr_fd(char *str, int fd);

#endif