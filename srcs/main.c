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
//	cmd.filename = ft_strdupcat("/bin/", cmd.argv[0]);
	cmd.filename = get_cmd_path(cmd.argv[0], path);
	if (cmd.filename != NULL)
		printf("%s\n", cmd.filename);
	else
		printf("invalid path\n");
	execute_cmd(cmd);
	return (0);
}
