#include "pipex.h"

// void    child(f1, argv[cmd])
// {
//     dup2(f1, STDIN_FILENO);
//     close(end[0]);

//     // execve(cmd1)
// }

// void    parrent(//argv[cmd])
// {
//     int status;

//     waitpid(-1, &status, 0);
//     dup2(f2, STDOUT_FILENO);
//     close(end[1]);
//     close(f2);
//     // execve(cmd2)
// }

// void    pipex(int fd1, int fd2, char **argv, char **envp)
// {
//     int     end[2];
//     pid_t   parent;

//     pipe(end);
//     parrent = fork();
//     if (parent < 0)
//         return (perror("Fork: "));
//     if (!parent)
//         child(f1, cmd1);
//     else
//         parent(f2, cmd2);
// }

// int main(int argc, char **argv, char **envp)
// {
//     // int f1;
//     // int f2;
//     char    *path;
//     char *args[] = {"ls", "-l", "-a", (char *)0};

        ft_split(argv[2], ' ');
//     // f1 = open(argv[1], O_RDONLY);
//     // f2 = opwn(argv[4], O_CREAR | O_RDWR | O_TRUNC, 0644);
//     // if (f1 < 0 || f2 < 0)
//     //     return (-1);
//     // if (id == 0)
//     //     child(argv[2]);
//     // else
//     //     parrent(argv[]);
//     path = search(envp, argv[1]);
//     printf("%s\n", path);

//     execve(path, args, envp);
//     printf("ERROR\n");

// }

int main ()
  { char *argv[]={"ls",NULL};
     (execve(argv[1] ,&argv[1],env));
   
    return 0;
  }  
 