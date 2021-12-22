/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:34:31 by cel-mhan          #+#    #+#             */
/*   Updated: 2021/12/22 00:35:13 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*search(char **path, char *cmd);
size_t	ft_strlen(const char	*str);
char	*search(char **path, char *cmd);
void	ft_putstr_fd(char *str, int fd);
int find_env(char **envp, char *pwd);
int	ft_strncmp(char *s1, char *s2, size_t n);

#endif
