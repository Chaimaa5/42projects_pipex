char    *ft_access(char *path)
{
    if (access(path, R_OK) ==)
    {
        ft_putstr("You have read access to: ");
        ft_putstr(path);
    }
    else if (access(path, W_OK))
    {
        ft_putstr("You have write access to: ");
        ft_putstr(path);
    }
    else if (access(path, X_OK))
    {
        ft_putstr("You have search access to: ");
        ft_putstr(path);
    }
}