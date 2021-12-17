#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd[2];
    int x;
    int y;

    x = 0;
    y = 0;
    if (pipe(fd) == -1)
    {
        printf("error occured");
        return 1;
    }
    int id = fork();
      if (id == -1)
    {
        printf("error occured while creating the child");
        return 2;
    }
    if (id == 0)//child pocess
    {
        close(fd[0]);// standard, to close one of the fd once working on the other
        printf("Input a number\n");
        scanf("%d", &x);
        write(fd[1], &x, sizeof(int));
        close(fd[1]);// closed and we don't have to write on it
    }
    else
    {
        close(fd[1]);
        read(fd[0], &y, sizeof(int));
        close(fd[0]);
        printf("got from child process %d", y);
    }
    return 0;
}