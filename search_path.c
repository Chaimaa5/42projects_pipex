#include "pipex.h"

char    *search(char **path, char *cmd)
{
    int     i;
    char    **paths;
    char    *x;

    i = 0;
    paths = ft_split(path[6], '=');
    paths = ft_split(paths[1], ':');
    while (paths[i])
    {
        x = ft_strjoin(paths[i], "/");
        x = ft_strjoin(x, cmd);
        if (access(x, F_OK) == 0)
            return (paths[i]);
        i++;
    }
    return(NULL);
}

