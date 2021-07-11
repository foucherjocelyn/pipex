#include <unistd.h>
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	t_fd	fd;

	if (argc != 3)
		return (-1);
	pipe(fd.pipefd);
	path = ft_getenv(envp, "PATH");
	fd.fdin = STDIN_FILENO;
	fd.fdout = fd.pipefd[1];
	fork_and_execute(argv[1], path, envp, fd);
	fd.fdin = fd.pipefd[0];
	fd.fdout = STDOUT_FILENO;
	fork_and_execute(argv[2], path, envp, fd);
	close(fd.pipefd[0]);
	close(fd.pipefd[1]);
	wait(0);
	wait(0);
	return (0);
}
