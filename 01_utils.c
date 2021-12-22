/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:35:19 by cel-mhan          #+#    #+#             */
/*   Updated: 2021/12/22 00:35:36 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

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
