#include "pipex.h"

char    *search(char **path, char *cmd)
{
    int     i;
    char    **paths;
    char    *x;
	char	*file;

    i = 0;
    paths = ft_split(path[6], '=');
    paths = ft_split(paths[1], ':');
    while (paths[i])
    {
        x = ft_strjoin(paths[i], "/");
        x = ft_strjoin(x, cmd);
        if (access(x, F_OK) == 0)
		{
			file = ft_strjoin(paths[i], "/");
			file = ft_strjoin(file, cmd);
            return (file);
		}
        i++;
    }
    return(NULL);
}

void	ft_putstr_fd(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		len2;
	int		i;
	int		len1;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i++ < len1)
		p[i - 1] = s1[i - 1];
	while (i++ < len1 + len2 + 1)
		p[i - 2] = s2[i - len1 - 2];
	p[len1 + len2] = '\0';
	return (p);
}

void	check_acess(char *path)
{
	if (access(path, F_OK) != 0)
		ft_putstr_fd("File does not exist\n", 2);
	if (access(path, R_OK) != 0)
		ft_putstr_fd("Permission denied\n", 2);
	if (access(path, W_OK) != 0)
		ft_putstr_fd("You have write access\n", 2);
}