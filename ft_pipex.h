/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:32:14 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/01/04 18:10:23 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

int		error(char *msg);
int		fdesc(char mode, char *file);
int		ft_execeve(char *cmd, char **envp);
int		child(int fdin, int fdout, char *cmd, char **envp, int fdclose);
void	finish(int pipefd[2], int id, int id1);

#endif