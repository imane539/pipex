#include "ft_pipex.h"

int	error(char *msg)
{
	ft_printf("%s %s\n", msg, strerror(errno));
	return (1);
}

int	fdesc(char mode, char *file)
{
	int	fd;

	fd = -1;
	if (mode == 'r')
	{
		fd = open(file, O_RDONLY);
		if (fd == -1 || access(file, R_OK) == -1)
			return (error("you can't read from this file:("));
	}
	if (mode == 'w')
	{
		fd = open(file, O_WRONLY);
		if (fd == -1 || access(file, W_OK) == -1)
			return (error("you can't write in this file:( "));
	}
	return (fd);
}

int	ft_execeve(char *cmd, char **envp)
{
	char	**argv;
	size_t	size;
	char	*path;
	char	*tes;

	tes = ft_strdup("/usr/bin/");
	argv = ft_split(cmd, ' ');
	size = ft_strlen("/usr/bin/") + ft_strlen(argv[0]) + 1;
	path = ft_strlcat(tes, argv[0], size);
	if (execve(path, argv, envp) == -1)
		return (error("failed to exec :( "));
	return (0);
}

int	child(int fdin, int fdout, char *cmd, char **envp, int fdclose)
{
	if (dup2(fdin, STDIN_FILENO) == -1)
		return (error("failed to duplicate :("));
	close(fdin);
	if (dup2(fdout, STDOUT_FILENO) == -1)
		return (error("failed to duplicate :("));
	close(fdout);
	close(fdclose);
	return (ft_execeve(cmd, envp));
}
void	finish(int pipefd[2], int id, int id1)
{
	close(pipefd[1]);
	close(pipefd[0]);
	printf("pid %d\n", waitpid(id, NULL, 0));
	printf("pid %d\n", waitpid(id1, NULL, 0));
}
