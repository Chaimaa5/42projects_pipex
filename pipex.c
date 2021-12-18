#include "pipex.h"

void    child(int f1, char *argv)
{
    char  *path;
    char  **cmd;

    cmd = ft_split(argv, ' ');
    path = search(envp, cmd[0]);
    dup2(f1, STDIN_FILENO);
    close(end[0]);
    if (execve(path, args, envp) == -1)
    {
      ft_putstr_fd("usage: ./pipex <file1> <cmd1> <cmd2> <file2>", 2);
      ft_putstr_fd("file doesn't exist", 2);
    }
    close(fd);
}

void    parrent(int fd, char *argv)
{
    int status;
    char  *path;
    char  **cmd;

    cmd = ft_split(argv, ' ');
    path = search(envp, cmd[0]);
    waitpid(-1, &status, 0);
    dup2(f2, STDOUT_FILENO);
    close(end[1]);
    if (execve(path, args, envp) == -1)
    {
      ft_putstr_fd("usage: ./pipex <file1> <cmd1> <cmd2> <file2>", 2);
      ft_putstr_fd("file doesn't exist", 2);
    }
    close(fd);
}

void    pipex(int fd1, int fd2, char **argv, char **envp)
{
    int     end[2];
    pid_t   parent;

    pipe(end);
    parrent = fork();
    if (parent < 0)
        return (perror("Fork: "));
    if (!parent)
        child(f1, cmd1);
    else
        parent(f2, cmd2);
}

int main(int argc, char **argv, char **envp)
{
    int f1;
    int f2;

    f1 = open(argv[1], O_RDONLY);
    f2 = open(argv[4], O_CREAR | O_RDWR | O_TRUNC, 0644);
    if (f1 < 0 || f2 < 0)
        return (-1);
    pipex(f1, f2, argv, envp);
}

