#include "pipex.h"

int	execute_cmd(t_cmd cmd)
{
	if (cmd.filename != NULL)
		execve(cmd.filename, cmd.argv, cmd.envp);
	perror("Error");
	free(cmd.filename);
	ft_free_array((void **)cmd.argv);
	free(cmd.argv);
	return (-1);
}

t_cmd	init_command(char *cmdstring, char *path, char **envp)
{
	t_cmd	cmd;

	cmd.envp = envp;
	parse_cmd(&cmd, cmdstring);
	cmd.filename = get_cmd_path(cmd.argv[0], path);
	return (cmd);
}

int	fork_and_execute(char *cmdstring, char *path, char **envp, t_fd fd)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error : ");
		return (-1);
	}
	if (pid == 0)
	{
		redirect_pipe(fd.fdin, fd.fdout);
		close_fds(fd);
		execute_cmd(init_command(cmdstring, path, envp));
		exit(EXIT_FAILURE);
	}
	return (0);
}
