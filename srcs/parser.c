#include "pipex.h"

static int	nb_args(char **args)
{
	int	nb;

	nb = 0;
	while (args[nb] != NULL)
		nb++;
	return (nb);
}

static int	copy_args(t_cmd *cmd, char **args)
{
	int	i;

	i = 0;
	cmd->argv = malloc(sizeof(char *) * (nb_args(args) + 1));
	if (cmd->argv == NULL)
	{
		perror("Error : copy_args : ");
		return (-1);
	}
	while (args[i] != NULL)
	{
		cmd->argv[i] = args[i];
		i++;
	}
	cmd->argv[i] = NULL;
	return (0);
}

int	parse_cmd(t_cmd *cmd, char *raw_cmd)
{
	char	**splitted;

	splitted = ft_split(raw_cmd, ' ');
	if (splitted == NULL)
	{
		perror("Error : parse_cmd : ");
		return (-1);
	}
	if (copy_args(cmd, splitted) == -1)
	{
		//TODO:free splitted
		return (-1);
	}
	return (0);
}
