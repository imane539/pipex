/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:48:00 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/01/16 14:35:22 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

t_data	addtostruct(char id, char *cmd, char **envp, char *file)
{
	t_data	data;

	data.id = id;
	data.cmd = cmd;
	data.envp = envp;
	data.file = file;
	return (data);
}

int	child(int counts[2], int pipefd[2], char **envp, char **av)
{
	if (counts[0] == 0)
		return (first_last(addtostruct('r', av[2], envp, av[1]), pipefd[0],
				pipefd));
	else if (counts[0] == counts[1] - 3 - 1)
		return (first_last(addtostruct('w', av[counts[1] - 2], envp,
					av[counts[1] - 1]), pipefd[1], pipefd));
	else
		return (middle(addtostruct('x', av[2 + counts[0]], envp, NULL),
				pipefd));
}

int	parent(int ac, char **av, char **envp)
{
	int	pipefd[2];
	int	counts[2];

	int (count), (id);
	count = 0;
	counts[0] = count;
	counts[1] = ac;
	while (count < ac - 3)
	{
		if (pipe(pipefd) == -1)
			error("failed to create a pipe :( ");
		id = fork();
		if (id == -1)
			error("failed to create a child :( ");
		if (id == 0)
		{
			counts[0] = count;
			return (child(counts, pipefd, envp, av));
		}
		finish(pipefd);
		count++;
	}
	while (count-- > 0)
		wait(NULL);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int	pipefd[2];

	if (ac < 5)
		return (1);
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		if (pipe(pipefd) == -1)
			error("failed to create a pipe :( ");
		return (here_doc(av, envp, pipefd));
	}
	return (parent(ac, av, envp));
}
