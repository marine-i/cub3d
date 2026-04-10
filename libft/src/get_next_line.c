/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfranc <marfranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:23:04 by marfranc          #+#    #+#             */
/*   Updated: 2025/11/04 14:31:43 by marfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//lire dans un buffer temporaire avec read
//ajouter ce que j'ai lu a ce que j'avais deja stocke (la stash)
//regarder si je trouve \n
//si oui decouper jusqu'au \n et renvoies cette ligne
//garde le reste pour l'appel suivant 

//element que la fonction utilise : fd et buffer size 
// si fd < 0 renvoie -1 ou buffer

#include "libft.h"

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = malloc(ft_strlen(stash + i) + 1);
	if (!new_stash)
		return (NULL);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*read_next_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc (i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_and_fill_stash(int fd, char *stash)
{
	char		*tmp;
	char		*buf;
	int			nbyte;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	nbyte = 1;
	while ((!stash || !ft_strchr(stash, '\n')) && nbyte > 0)
	{
		nbyte = read (fd, buf, BUFFER_SIZE);
		if (nbyte < 0)
			return (free(buf), free(stash), NULL);
		buf[nbyte] = '\0';
		if (!stash)
			stash = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(stash, buf);
			free (stash);
			stash = tmp;
		}
	}
	return (free (buf), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_fill_stash (fd, stash);
	if (!stash)
		return (NULL);
	line = read_next_line(stash);
	stash = clean_stash(stash);
	return (line);
}
