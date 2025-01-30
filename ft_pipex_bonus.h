/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:35:38 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/01/16 14:35:43 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H

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
int			fdesc(char mode, char *file, int id);
int			ft_execeve(char *cmd, char **envp);
int			first_last(t_data data, int fdclose, int pipefd[2]);
void		finish(int pipefd[2]);
t_data		addtostruct(char id, char *cmd, char **envp, char *file);
int			middle(t_data data, int pipefd[2]);
char		**getpaths(char **envp);
char		*check_path(char **paths, char *cmd);
void		not_found(char *cmd, char *msg);
char		*get_text(char **av);
int			child_doc(t_data data, int fdclose, int pipefd[2]);
char		*tmp_file(char **av);
char		*ft_free(char *text, char *limiter);
int			here_doc(char **av, char **envp, int pipefd[2]);
int			finish_doc(int pipefd[2], int id, int id1, char *file);
#endif
