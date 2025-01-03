/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:33:46 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/12/31 15:45:03 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_pipex.h"
int	main(int ac, char **av, char **envp)
{
	int	pipefd[2];
	int(fd0), (fd1), (id), (id1);

	if (ac != 5)
		return (1);
	if (pipe(pipefd) == -1)
		return(error("failed to create a pipe :( "));
	if ((fd0 = fdesc('r', av[1])) == 1)
		return(1);
	id = fork();
	if (id == -1)
		return(error("failed to create a child :( "));
	if (id == 0)
		return(child(fd0, pipefd[1], av[2], envp, pipefd[0]));
	else
	{
		if ((fd1 = fdesc('w', av[4])) == 1)
			return (1);
		id1 = fork();
		if (id1 == -1)
			return (error("failed to create a child 2:( "));
		if (id1 == 0)
			return (child(pipefd[0], fd1, av[3], envp, pipefd[1]));
	}
	close( pipefd[1]);
	close(pipefd[0]);
	printf("pid %d\n",waitpid(id,NULL, 0));
	printf("pid %d\n", waitpid(id1, NULL, 0));
}
