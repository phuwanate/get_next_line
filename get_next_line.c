/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:06:08 by plertsir          #+#    #+#             */
/*   Updated: 2023/03/10 11:56:09 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buff, char *stash)
{
	int		read_status;
	char	*stash_temp;

	read_status = 1;
	while (read_status != 0)
	{
		read_status = read(fd, buff, BUFFER_SIZE);
		if (read_status == -1)
			return (NULL);
		if (read_status == 0)
			break ;
		buff[read_status] = '\0';
		if (!stash)
			stash = ft_strdup("");
		stash_temp = stash;
		stash = ft_strjoin(stash_temp, buff);
		free(stash_temp);
		stash_temp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (stash);
}

char	*ft_clean(char *line)
{
	int		i;
	size_t	len_stash;
	char	*stash;

	len_stash = ft_strlen(line);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	stash = ft_substr(line, i + 1, len_stash - i);
	if (*stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	line[i + 1] = '\0';
	return (stash);
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
	line = read_file(fd, buff, stash);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	stash = ft_clean(line);
	return (line);
}
