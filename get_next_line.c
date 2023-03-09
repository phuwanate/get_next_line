/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:06:08 by plertsir          #+#    #+#             */
/*   Updated: 2023/03/09 22:46:55 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buff, char *stash)
{
	int		read_status;

	read_status = 1;
	while(read_status != 0)
	{
		if(read_status == -1)
			return (NULL);
		if(read_status == 0)
			break;
		if(!stash)
			stash = ft_strdup("");
		read_status = read(fd, buff, BUFFER_SIZE);
		buff
		stash = ft_strjoin(stash, buff);
		if (ft_strchr(stash, '\n') != NULL)
			break ;
	}
	return(stash);
}

char	ft_clean(char *stash)
{
	
}

char    *get_next_line(int fd)
{
	char			*buff;
	char			*line;
	static char		*stash;
	
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) + sizeof(char));
	if(!buff)
		return (NULL);
	stash = read_file(fd, buff, stash);
	if(!stash)
		return (NULL);
	line = ft_clean(stash);
	return(line);    
}