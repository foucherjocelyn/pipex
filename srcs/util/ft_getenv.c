#include "util.h"

char	*ft_getenv(char **envp, const char *name)
{
	int	var;

	var = 0;
	while (envp[var] != NULL)
	{
		if (ft_strncmp(envp[var], name, ft_strlen(name)) == 0)
			return (&(envp[var][ft_strlen(name) + 1]));
		var++;
	}
	return (NULL);
}
