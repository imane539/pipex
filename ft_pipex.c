/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:33:46 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/01/07 16:31:16 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	pipefd[2];

	int (id), (id1);
	if (ac != 5)
		return (1);
	if (pipe(pipefd) == -1)
		return (error("failed to create a pipe :( "));
	id = fork();
	if (id == -1)
		return (error("failed to create a child :( "));
	if (id == 0)
	{
		t_data data;
		data.id = 'r';
		data.cmd=av[2];
		data.envp=envp;
		data.file= av[1];
		return (child(data, pipefd[0],pipefd));
	}
	else
	{
		id1 = fork();
		if (id1 == -1)
			return (error("failed to create a child 2:( "));
		if (id1 == 0)
		{
			t_data data;
			data.id = 'w';
			data.cmd=av[3];
			data.envp=envp;
			data.file=av[ac-1];
			return (child(data,pipefd[1],pipefd));
		}
		finish(pipefd, id, id1);
	}
}
