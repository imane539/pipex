/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:39:58 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/01/16 14:40:02 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

void	error(char *msg)
{
	perror(msg);
	exit(1);
}

int	fdesc(char mode, char *file, int id)
{
	int	fd;

	if (mode == 'r')
	{
		fd = open(file, O_RDONLY);
		if (fd == -1 || access(file, R_OK) == -1)
			error("you can't read from this file:(");
	}
	if (mode == 'w')
	{
		if (id == 1)
			fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else
			fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1 || access(file, W_OK) == -1)
			error("you can't write in this file:( ");
	}
	return (fd);
}

char	**getpaths(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i] && (ft_strnstr(envp[i], "PATH", 4) == NULL))
		i++;
	if (envp[i] && (ft_strnstr(envp[i], "PATH", 4)))
	{
		path = ft_split(envp[i] + 5, ':');
		return (path);
	}
	return (NULL);
}

char	*check_path(char **paths, char *cmd)
{
	int		i;
	char	*path;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
		free(path);
	}
	return (NULL);
}

void	finish(int pipefd[2])
{
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[1]);
	close(pipefd[0]);
}
