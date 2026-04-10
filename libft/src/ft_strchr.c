/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:50:57 by maiguna           #+#    #+#             */
/*   Updated: 2025/11/22 13:43:12 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == s[i])
	{
		return ((char *)&s[i]);
	}
	return (0);
}
/*#include <stdio.h>
#include <string.h>
int main()
{
	char *s = "bonjour";
	printf("ft_strchr : %s\n", ft_strchr(s, 'j'));
	printf("strchr    : %s\n", strchr(s, 'j'));

	printf("ft_strchr : %s\n", ft_strchr(s, '\0'));
	printf("strchr    : %s\n", strchr(s, '\0'));

	printf("ft_strchr : %s\n", ft_strchr(s, 'p'));
	printf("strchr    : %s\n", strchr(s, 'p'));

	printf("ft_strchr : %s\n", ft_strchr(s, 'b'));
	printf("strchr    : %s\n", strchr(s, 'b'));

}*/