/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:22:32 by maiguna           #+#    #+#             */
/*   Updated: 2025/11/22 13:43:12 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *src)
{
	size_t		i;
	char		*cpy;

	if (!src)
		return (NULL);
	i = ft_strlen(src);
	cpy = malloc(sizeof(char) * (i + 1));
	if (!cpy)
	{
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

/*#include <stdio.h>
int	main()
{
	char *test = "Hello 42";
	char *cpytest = ft_strdup(test);
	char *vraitest = strdup(test);
	printf("%s\n", test);
	printf("%s\n", cpytest);
	printf("%s\n", vraitest);

}*/