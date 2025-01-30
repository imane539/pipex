/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:50:26 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/01/16 14:32:37 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

void	not_found(char *cmd, char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(cmd, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

char	*ft_free(char *text, char *limiter)
{
	char	*tmp;

	tmp = ft_strjoin(text, limiter);
	free(text);
	text = ft_strdup(tmp);
	free(tmp);
	return (text);
}

int	ft_execeve(char *cmd, char **envp)
{
	char	**argv;
	char	*path;
	char	**paths;

	argv = ft_split(cmd, ' ');
	if (!ft_strchr(argv[0], '/'))
	{
		paths = getpaths(envp);
		if (!paths)
			not_found(argv[0], "command not found: ");
		path = check_path(paths, argv[0]);
		if (!path)
			not_found(argv[0], "command not found: ");
		if (access(path, X_OK) != 0)
			not_found(argv[0], "permission denied: ");
	}
	else
		path = argv[0];
	if (execve(path, argv, envp) == -1)
	{
		free(path);
		error("failed to exec :( ");
	}
	return (0);
}

int	first_last(t_data data, int fdclose, int pipefd[2])
{
	int (fd), (out), (in);
	fd = fdesc(data.id, data.file, 2);
	if (data.id == 'r')
	{
		in = fd;
		out = pipefd[1];
		if (dup2(in, STDIN_FILENO) == -1)
			error("failed to duplicate 4:(");
		close(in);
	}
	else
		out = fd;
	if (dup2(out, STDOUT_FILENO) == -1)
			error("failed to duplicate 4:(");

	close(out);
	close(fdclose);
	return (ft_execeve(data.cmd, data.envp));
}

int	middle(t_data data, int pipefd[2])
{
	close(pipefd[0]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		error("failed to duplicate 2:(");
	close(pipefd[1]);
	return (ft_execeve(data.cmd, data.envp));
}
