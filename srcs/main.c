#include "pipex.h"
#include "string.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	char	path[100];

	if (argc !=2 )
		return (-1);
	cmd.envp = envp;
	parse_cmd(&cmd, argv[1]);
	strcpy(path, "/bin/");
	strcat(path, cmd.argv[0]);
	cmd.filename = malloc(100);
	strcpy(cmd.filename, path);
	execute_cmd(cmd);
	return (0);
}
