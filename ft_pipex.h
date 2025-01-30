/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:34:41 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/01/16 14:34:47 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "ft_printf/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_data
{
	char	id;
	char	*cmd;
	char	**envp;
	char	*file;
}			t_data;

void		error(char *msg);
int			fdesc(char mode, char *file);
char		**getpaths(char **envp);
char		*check_path(char **paths, char *cmd);
int			ft_execeve(char *cmd, char **envp);
int			finish(int pipefd[2], int id, int id1);

#endif
