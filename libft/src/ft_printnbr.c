/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:16:00 by maiguna           #+#    #+#             */
/*   Updated: 2025/08/01 18:35:04 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		count += ft_printchar('-');
		nbr = -nbr;
	}
	if (nbr >= 0 && nbr <= 9)
		count += ft_printchar(nbr + '0');
	else
	{
		count += ft_printnbr(nbr / 10);
		count += ft_printnbr(nbr % 10);
	}
	return (count);
}

int	ft_printnbr_unsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr <= 9)
		count += ft_printchar(nbr + '0');
	else
	{
		count += ft_printnbr_unsigned(nbr / 10);
		count += ft_printnbr_unsigned(nbr % 10);
	}
	return (count);
}
