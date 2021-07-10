#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	char	*path;

	if (argc != 2)
		return (-1);
	path = ft_getenv(envp, "PATH");
	cmd.envp = envp;
	parse_cmd(&cmd, argv[1]);
	strcpy(path, "/bin/");
	strcat(path, cmd.argv[0]);
	cmd.filename = malloc(100);
	strcpy(cmd.filename, path);
	execute_cmd(cmd);
	return (0);
}
