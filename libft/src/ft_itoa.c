/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:06:59 by maiguna           #+#    #+#             */
/*   Updated: 2025/08/01 18:35:41 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	len_nb(long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (0 < n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_result(long len, int sign, long result, char *str)
{
	while (0 < len)
	{
		len--;
		str[len + sign] = (result % 10) + '0';
		result /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	result;
	int		sign;
	int		len;
	char	*str;

	sign = 0;
	result = n;
	if (result < 0)
	{
		sign = 1;
		result = -result;
	}
	len = len_nb(result);
	str = malloc (sizeof(char) * (len + sign + 1));
	if (!str)
		return (NULL);
	if (result == 0)
		str[0] = '0';
	if (sign == 1)
		str[0] = '-';
	str[len + sign] = '\0';
	return (ft_result(len, sign, result, str));
}
