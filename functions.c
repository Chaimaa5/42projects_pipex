/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 02:51:20 by cel-mhan          #+#    #+#             */
/*   Updated: 2021/11/19 02:30:18 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


static int	count_words(char *s, char c)
{
	int	i;
	int	f;
	int	k;

	i = 0;
	k = 0;
	f = 0;
	while (s[i])
	{
		if (s[i] == c)
			f = 0;
		else
		{
			if (f == 0)
				k++;
			f = 1;
		}
		i++;
	}
	return (k);
}

static int	letter(char *s, char c, int j)
{
	int	i;

	i = 0;
	while (s[j] != c && s[j])
	{
		i++;
		j++;
	}
	return (i);
}

static char	*ft_strndup(char *src, char c, int j)
{
	int		i;
	char	*dst;
	int		len;

	len = letter(src, c, j);
	dst = malloc(sizeof(char) * len + 1);
	i = 0;
	if (!dst)
		return (NULL);
	while (i < len && src[j] != c)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**array;
	int		j;
	int		count;

	if (!s)
		return (NULL);
	j = 0;
	count = count_words((char *)s, c);
	array = (char **)malloc(sizeof(char *) * (count + 1));
	i = 0;
	if (!array)
		return (0);
	while (i < count)
	{
		while (s[j] == c)
			j++;
		array[i] = ft_strndup((char *)s, c, j);
		j += letter((char *)s, c, j);
		i++;
	}
	array[i] = NULL;
	return (array);
}


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