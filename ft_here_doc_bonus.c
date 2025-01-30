/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:33:11 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/01/16 14:42:49 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

char	*get_text(char **av)
{
	size_t	sizelim;
	char	*limiter;
	char	*text;
	int		readed;

	text = NULL;
	sizelim = ft_strlen(av[2]);
	while (1)
	{
		limiter = malloc(4096);
		write(0, "pipe heredoc> ", 14);
		readed = read(0, limiter, 4096);
		limiter[readed] = '\0';
		if (ft_strncmp(limiter, av[2], sizelim) == 0 && limiter[sizelim] == 10)
			return (free(limiter), text);
		if (!text)
			text = ft_strdup(limiter);
		else
			text = ft_free(text, limiter);
		free(limiter);
	}
	return (NULL);
}

int	child_doc(t_data data, int fdclose, int pipefd[2])
{
	int (fd), (out), (in);
	fd = fdesc(data.id, data.file, 1);
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

char	*tmp_file(char **av)
{
	int		fd;
	int		i;
	char	*text;

	char *(file), *(index);
	i = 0;
	text = get_text(av);
	index = ft_itoa(i);
	file = ft_strjoin("tmp", index);
	free(index);
	while (access(file, F_OK) == 0)
	{
		i++;
		free(file);
		index = ft_itoa(i);
		file = ft_strjoin("tmp", index);
		free(index);
	}
	fd = open(file, O_CREAT | O_RDWR, 0644);
	if (text)
	{
		write(fd, text, ft_strlen(text));
		free(text);
	}
	return (file);
}

int	finish_doc(int pipefd[2], int id, int id1, char *file)
{
	int	*status;
	int	st;

	close(pipefd[1]);
	close(pipefd[0]);
	status = malloc(2 * sizeof(int));
	waitpid(id, status, 0);
	st = WEXITSTATUS(*status);
	if (st == 1)
	{
		if (unlink(file) == -1)
			error("failed to remove :(");
		free(file);
		free(status);
		return (st);
	}
	waitpid(id1, status + 1, 0);
	st = WEXITSTATUS(*status + 1);
	free(status);
	if (unlink(file) == -1)
		error("failed to remove :(");
	free(file);
	return (st);
}

int	here_doc(char **av, char **envp, int pipefd[2])
{
	char	*file;

	int (id), (id1);
	file = NULL;
	file = tmp_file(av);
	id = fork();
	if (id == -1)
		error("failed to create a child :( ");
	if (id == 0)
	{
		return (child_doc(addtostruct('r', av[3], envp, file), pipefd[0],
				pipefd));
	}
	else
	{
		id1 = fork();
		if (id1 == -1)
			error("failed to create a child 2:( ");
		if (id1 == 0)
			return (child_doc(addtostruct('w', av[4], envp, av[5]), pipefd[1],
					pipefd));
		return (finish_doc(pipefd, id, id1, file));
	}
}
