/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:06:08 by plertsir          #+#    #+#             */
/*   Updated: 2023/03/10 01:38:48 by first            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buff, char *stash)
{
	int		read_status;

	read_status = 1;
	while (read_status != 0)
	{
		if (read_status == -1)
			return (NULL);
		if (read_status == 0)
			break ;
		if (!stash)
			stash = ft_strdup("");
		read_status = read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE + 1] = '\0';
		stash = ft_strjoin(stash, buff);
		if (ft_strchr(stash, '\n') != NULL)
			break ;
	}
	return (stash);
}

char	*ft_clean(char *stash)
{
	int		i;
	size_t	len_stash;
	char	*line;

	len_stash = ft_strlen(stash);
	i = 0;
	while (stash[i] != '\n' || stash[i] != '\0')
		i++;
	line = ft_substr(stash, 0, i + 1);
	while ((stash[len_stash] != '\n') && (len_stash != 0))
		len_stash--;
	stash = ft_strdup(&stash[len_stash]);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*buff;
	char			*line;
	static char		*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) + sizeof(char));
	if (!buff)
		return (NULL);
	stash = read_file(fd, buff, stash);
	free(buff);
	buff = NULL;
	if (!stash)
		return (NULL);
	line = ft_clean(stash);
	return (line);
}
