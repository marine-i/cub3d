/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:08:38 by maiguna           #+#    #+#             */
/*   Updated: 2025/11/22 13:43:12 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	ptr = 0;
	while (s[i])
	{
		if ((char)c == s[i])
		{
			ptr = (char *)&s[i];
		}
		i++;
	}
	if ((char)c == s[i])
	{
		ptr = (char *)&s[i];
	}
	return (ptr);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%s", ft_strrchr("hello\n", 'e'));
	printf("%s", strrchr("hello\n", 'e'));

}*/
