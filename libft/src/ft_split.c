/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiguna <maiguna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:38:38 by maiguna           #+#    #+#             */
/*   Updated: 2025/11/22 13:43:12 by maiguna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	*ft_free(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
	return (NULL);
}

static int	ft_count_words(char const *s, char c)
{
	int	nb_words;
	int	i;

	i = 0;
	nb_words = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			nb_words++;
		i++;
	}
	return (nb_words);
}

static void	ft_get_next_word(const char *s, char c, int *start, int *end)
{
	while (s[*start] == c)
		(*start)++;
	*end = *start;
	while (s[*end] != c && s[*end])
		(*end)++;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		nb_words;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	int (i) = 0;
	end = 0;
	start = 0;
	nb_words = ft_count_words(s, c);
	result = malloc (sizeof(char *) * (nb_words + 1));
	if (!result)
		return (NULL);
	while (i < nb_words)
	{
		ft_get_next_word(s, c, &start, &end);
		result[i] = ft_substr(s, start, (end - start));
		if (!result[i])
			return (ft_free(result, i));
		start = end;
		i++;
	}
	result[nb_words] = NULL;
	return (result);
}
/*int	main(void)
{
	char const	tab[] = "test_hello____42____________";
	char		sep;
	char		**result;
	int			i;

	sep = '_';
	i = 0;
	result = ft_split(tab, sep);
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
}*/
