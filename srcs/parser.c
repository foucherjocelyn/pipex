#include "pipex.h"

int	parse_cmd(t_cmd *cmd, char *raw_cmd)
{
	char	**splitted;

	splitted = ft_split(raw_cmd, ' ');
	if (splitted == NULL)
	{
		perror("Error : parse_cmd : ");
		return (-1);
	}
	cmd->argv = splitted;
	return (0);
}
