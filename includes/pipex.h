#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "util.h"

typedef struct	s_cmd
{
	char	*filename;
	char	**argv;
	char	**envp;
}				t_cmd;

int	parse_cmd(t_cmd *cmd, char *raw_cmd);
int	execute_cmd(t_cmd cmd);

#endif
