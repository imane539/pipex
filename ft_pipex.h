/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:32:14 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/01/07 16:27:41 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "ft_printf/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_data
{
    char id;
    char *cmd;
    char **envp;
    char *file;
}					t_data;

int		error(char *msg);
int		fdesc(char mode, char *file);
int		ft_execeve(char *cmd, char **envp);
int	child(t_data data,int fdclose,int pipefd[2]);
void	finish(int pipefd[2], int id, int id1);


#endif