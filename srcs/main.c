#include <unistd.h>
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	t_fd	fd;

	if (argc != 5)
		return (-1);
	fd.filein = open(argv[1], O_RDONLY);
	fd.fileout = open(argv[4], O_WRONLY | O_TRUNC);
	pipe(fd.pipefd);
	path = ft_getenv(envp, "PATH");
	fd.fdin = fd.filein;
	fd.fdout = fd.pipefd[1];
	fork_and_execute(argv[2], path, envp, fd);
	fd.fdin = fd.pipefd[0];
	fd.fdout = fd.fileout;
	fork_and_execute(argv[3], path, envp, fd);
	close(fd.pipefd[0]);
	close(fd.pipefd[1]);
	close(fd.filein);
	close(fd.fileout);
	wait(0);
	wait(0);
	return (0);
}
