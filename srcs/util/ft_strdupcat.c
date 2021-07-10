#include <stdlib.h>
#include "util.h"

char	*ft_strdupcat(char *s1, char *s2)
{
	char	*result;

	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	ft_strcat(result, s1);
	ft_strcat(result, s2);
	return (result);
}
