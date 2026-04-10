/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfranc <marfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:53:12 by maiguna           #+#    #+#             */
/*   Updated: 2025/12/06 14:53:13 by marfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	check_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && check_set(s1[start], set))
		start++;
	while (check_set(s1[end - 1], set) && end > start)
		end--;
	result = malloc(sizeof(char) * ((end - start) + 1));
	if (!result)
		return (NULL);
	while (start < end)
	{
		result[i] = s1[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}
// #include <stdio.h>

// int	main()
// {
// 	char *result = ft_strtrim("    ", " ");
// 	printf("%s\n", result);
// 	printf("%s\n", ft_strtrim("*** * test******test*** * ** ** ", "* t"));
// 	printf("%s\n", ft_strtrim("*** * test*** t***test*** * ** ** ", "* t"));
// 	free(result);
// 	return(0);
// }