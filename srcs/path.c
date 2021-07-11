#include <unistd.h>
#include <fcntl.h>
#include "pipex.h"

static char	*ft_strdupcatwithslash(char *s1, char *s2)
{
	char	*result;
	int		len;

	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	ft_strcat(result, s1);
	len = ft_strlen(result);
	result[len] = '/';
	result[len + 1] = '\0';
	ft_strcat(result, s2);
	return (result);
}

char	*get_cmd_path(char *filename, char *path)
{
	char	**every_path;
	int		i;
	char	*pathname;

	every_path = ft_split(path, ':');
	if (every_path == NULL)
	{
		perror("Error : split in get_cmd_path");
		return (NULL);
	}
	i = 0;
	while (every_path[i] != NULL)
	{
		pathname = ft_strdupcatwithslash(every_path[i], filename);
		if (pathname == NULL)
		{
			perror("Error : ft_strdupcat in get_cmd_path");
			return (NULL);
		}
		if (access(pathname, X_OK) == 0)
		{
			ft_free_array((void **)every_path);
			free(every_path);
			return (pathname);
		}
		free(pathname);
		i++;
	}
	ft_free_array((void **)every_path);
	free(every_path);
	return (NULL);
}
