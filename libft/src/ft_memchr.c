/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:09:29 by maiguna           #+#    #+#             */
/*   Updated: 2025/11/22 13:43:13 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;

	if (!s)
		return (NULL);
	i = 0;
	src = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)c == src[i])
		{
			return (src + i);
		}
		i++;
	}
	return (NULL);
}
