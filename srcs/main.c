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
	cmd.filename = ft_strdupcat("/bin/", cmd.argv[0]);
	execute_cmd(cmd);
	return (0);
}
