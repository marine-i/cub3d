/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:22:55 by maiguna           #+#    #+#             */
/*   Updated: 2025/08/01 18:35:04 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printhex(unsigned int nbr)
{
	int			count;
	const char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (nbr < 16)
		count += ft_printchar(hex[nbr]);
	else
	{
		count += ft_printhex(nbr / 16);
		count += ft_printhex(nbr % 16);
	}
	return (count);
}

int	ft_printhex_upper(unsigned int nbr)
{
	int			count;
	const char	*hex;

	hex = "0123456789ABCDEF";
	count = 0;
	if (nbr < 16)
		count += ft_printchar(hex[nbr]);
	else
	{
		count += ft_printhex_upper(nbr / 16);
		count += ft_printhex_upper(nbr % 16);
	}
	return (count);
}

int	ft_printhex_pointeur(unsigned long nbr)
{
	int			count;
	const char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (nbr < 16)
		count += ft_printchar(hex[nbr]);
	else
	{
		count += ft_printhex_pointeur(nbr / 16);
		count += ft_printhex_pointeur(nbr % 16);
	}
	return (count);
}

int	ft_printp(void *nbr)
{
	int		count;

	count = 0;
	if (!nbr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		count += ft_printstr("0x");
		count += ft_printhex_pointeur((unsigned long)nbr);
	}
	return (count);
}
