#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include "util.h"

typedef struct s_cmd
{
	char	*filename;
	char	**argv;
	char	**envp;
}t_cmd;

typedef struct s_fd
{
	int	fdin;
	int	fdout;
	int	pipefd[2];
}t_fd;

int		parse_cmd(t_cmd *cmd, char *raw_cmd);
int		execute_cmd(t_cmd cmd);
char	*get_cmd_path(char *filename, char *path);
int		fork_and_execute(char *cmdstring, char *path, char **envp, t_fd fd);
t_cmd	init_command(char *cmdstring, char *path, char **envp);
int		redirect_pipe(int fdin, int fdout);

#endif
