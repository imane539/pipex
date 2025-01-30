/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:33:50 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/01/16 14:40:44 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

t_data	addtostruct(char id, char *cmd, char **envp, char *file)
{
	t_data	data;

	data.id = id;
	data.cmd = cmd;
	data.envp = envp;
	data.file = file;
	return (data);
}

void	not_found(char *cmd, char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(cmd, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
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

int	child(t_data data, int fdclose, int pipefd[2])
{
	int (fd), (out), (in);
	fd = fdesc(data.id, data.file);
	if (data.id == 'r')
	{
		in = fd;
		out = pipefd[1];
	}
	else
	{
		in = pipefd[0];
		out = fd;
	}
	if (dup2(in, STDIN_FILENO) == -1)
		error("failed to duplicate :(");
	close(in);
	if (dup2(out, STDOUT_FILENO) == -1)
		error("failed to duplicate :(");
	close(out);
	close(fdclose);
	return (ft_execeve(data.cmd, data.envp));
}

int	main(int ac, char **av, char **envp)
{
	int	pipefd[2];

	int (id), (id1);
	if (ac != 5)
		exit(1);
	if (pipe(pipefd) == -1)
		error("failed to create a pipe :( ");
	id = fork();
	if (id == -1)
		error("failed to create a child :( ");
	if (id == 0)
		return (child(addtostruct('r', av[2], envp, av[1]), pipefd[0], pipefd));
	else
	{
		id1 = fork();
		if (id1 == -1)
			error("failed to create a child 2:( ");
		if (id1 == 0)
			return (child(addtostruct('w', av[3], envp, av[ac - 1]), pipefd[1],
					pipefd));
	}
	return (finish(pipefd, id, id1));
}
