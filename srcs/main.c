#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;

	if (argc != 2)
		return (-1);
	path = ft_getenv(envp, "PATH");
	fork_and_execute(argv[1], path, envp);
	return (0);
}
