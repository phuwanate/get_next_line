/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:14:42 by plertsir          #+#    #+#             */
/*   Updated: 2023/03/09 22:46:57 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(s);
	ptr = (char *)s;
	if (c == '\0')
		return (&ptr[len_s]);
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (char)c)
			return(&ptr[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	char	*ptr;
	char	*result;
	size_t	size;

	size = 0;
	ptr = (char *)s1;
	size = ft_strlen(ptr);
	dst = (char *)malloc(size + 1 * sizeof(char));
	result = dst;
	if (dst)
	{
		while (*ptr != '\0')
		{
			*dst++ = *ptr++;
		}
		*dst = '\0';
	}
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len_s1;
	size_t	len_s2;
	size_t	size;

	if (s1 == NULL || s2 == NULL)
		return (ft_strdup(""));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	size = len_s1 + len_s2;
	ptr = (char *)malloc((size + 1) * sizeof(char));
	if (ptr != NULL)
	{
		ft_strlcpy(ptr, s1, len_s1 + 1);
		ft_strlcpy(&ptr[len_s1], s2, len_s2 + 1);
	}
	return (ptr);
}
