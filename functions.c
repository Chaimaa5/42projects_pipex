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

static char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	while (src[i])
	{
		dst[i + len] = src[i];
		i++;
	}
	dst[i + len] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (0);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result)
		ft_strcat(ft_strcat(result, s1), s2);
	return (result);
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