/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:46:25 by maiguna           #+#    #+#             */
/*   Updated: 2025/11/22 13:43:13 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	i;
	size_t	j;

	if (!dst || !src)
		return (0);
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	i = size_dst;
	j = 0;
	if (size_dst >= size)
	{
		return (size + size_src);
	}
	while (src[j] && (i < (size - 1)))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (size_dst + size_src);
}
