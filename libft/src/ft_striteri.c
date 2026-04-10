/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:00:43 by maiguna           #+#    #+#             */
/*   Updated: 2025/11/22 13:43:12 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>
int	main()
{
	unsigned int	i;
	char	str[] = "bonjour";

	ft_striteri(str, test_ft_tolower);
	printf("%s\n", str);
}
void	test_ft_tolower(unsigned int i, char *c)
{

	if (c[i] >= 'a' && c[i] <= 'z')
	{
		c[i] = c[i] - 32;
	}
*/