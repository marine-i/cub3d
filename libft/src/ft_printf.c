/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:58:32 by maiguna           #+#    #+#             */
/*   Updated: 2025/08/01 18:35:04 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_format(const char *format, int i, va_list *ap)
{
	int	count;

	count = 0;
	if (format[i] == '%')
		count += ft_printchar('%');
	else if (format[i] == 'c')
		count += ft_printchar(va_arg(*ap, int));
	else if (format[i] == 's')
		count += ft_printstr(va_arg(*ap, char *));
	else if (format[i] == 'i' || format[i] == 'd')
		count += ft_printnbr(va_arg(*ap, int));
	else if (format[i] == 'u')
		count += ft_printnbr_unsigned(va_arg(*ap, unsigned int));
	else if (format[i] == 'x')
		count += ft_printhex(va_arg(*ap, unsigned int));
	else if (format[i] == 'X')
		count += ft_printhex_upper(va_arg(*ap, unsigned int));
	else if (format[i] == 'p')
		count += ft_printp(va_arg(*ap, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format(format, i, &ap);
			i++;
		}
		else
		{
			count += ft_printchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (count);
}
