#include <errno.h>
#include <stdio.h>

int	ft_error(char *message)
{
	perror(message);
	return (-1);
}
