#include "pipex.h"

int	execute_cmd(t_cmd cmd)
{
	execve(cmd.filename, cmd.argv, cmd.envp);
	perror("Error");
	return (-1);
}
