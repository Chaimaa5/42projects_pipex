int main(int argc, char **argv, char **envp)
{

    char    *path;
    char **se;
    int i;
    char **args;

    se = ft_split(argv[1], ' ');
    path = search(envp, se[0]);
    printf("%s", path);
    while (se[i])
    {
      printf("%s\n", se[i]);
      i++;
    }
    execve(path, se, envp);
}

