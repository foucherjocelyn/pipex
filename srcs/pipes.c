#include <unistd.h>
#include <stdio.h>
#include "pipex.h"

int	close_fds(t_fd fd)
{
	close(fd.pipefd[0]);
	close(fd.pipefd[1]);
	close(fd.filein);
	close(fd.fileout);
	return (0);
}

int	redirect_pipe(int fdin, int fdout)
{
	dup2(fdin, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	if (fdin != STDIN_FILENO)
		close(fdin);
	if (fdout != STDOUT_FILENO)
		close(fdout);
	return (0);
}
