#include "main.h"

void	free_all(t_data)
{
	//free tout
}


void	*ft_free(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
	return (NULL);
}
