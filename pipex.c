#include "pipex.h"

void    child(int fd, char *argv, char **envp)
{
    char  *path;
    char  **cmd;
     
    cmd = ft_split(argv, ' ');
    path = search(envp, cmd[0]);
    dup2(fd, STDIN_FILENO);
    close(fd);
    if (execve(path, cmd, envp) == -1)
    {
        perror("Error");
      ft_putstr_fd("usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
      ft_putstr_fd(cmd[0], 2);
    }
}

void    parent(int fd, char *argv, char **envp)
{
    char  *path;
    char  **cmd;

    cmd = ft_split(argv, ' ');
    path = search(envp, cmd[0]);
    waitpid(0, NULL, 0);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    if (execve(path, cmd, envp) == -1)
    {
        perror("Error");
      ft_putstr_fd("usage: ./pipex <file1> <cmd1> <cmd2> <file2>", 2);
      ft_putstr_fd(cmd[0], 2);
    }
}

void    pipex(int f1, int f2, char **argv, char **envp)
{
    int     end[2];
    pid_t   id;

    pipe(end);
    if (pipe(end))
        return ;
    id = fork();
    if (id < 0)
        return (perror("Fork: "));
    if (!id)
        child(f1, *argv, envp);
    else
        parent(f2, *argv, envp);
}

int main(int argc, char **argv, char **envp)
{
    int f1;
    int f2;

    f1 = open(argv[1], O_RDONLY);
    f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (f1 < 0 || f2 < 0)
        return (-1);
    pipex(f1, f2, argv, envp);
}

