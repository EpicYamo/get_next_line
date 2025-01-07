/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 04:14:09 by aaycan            #+#    #+#             */
/*   Updated: 2025/01/06 04:14:09 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	tmp;

	i = 0;
	tmp = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == tmp)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

int	ft_count_to_end_of_line(char *left_c)
{
	int	i;

	i = 0;
	if (!left_c)
		return (0);
	while (left_c[i] != '\n' && left_c[i] != '\0')
		i++;
	return (i);
}

char	*ft_check_newline_existence(char *left_c)
{
	int	i;

	i = 0;
	if (!left_c)
		return (NULL);
	while (left_c[i])
	{
		if (left_c[i] == '\n')
			return (left_c + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_modified(char *left_c, char *tmp)
{
	int		i;
	int		j;
	char	*joined_str;

	joined_str = malloc(ft_strlen(left_c) + ft_strlen(tmp) + 1);
	if (!joined_str)
	{
		free(left_c);
		return (NULL);
	}
	i = -1;
	while (left_c[++i] != '\0')
		joined_str[i] = left_c[i];
	j = 0;
	while (tmp[j] != '\0')
		joined_str[i++] = tmp[j++];
	joined_str[ft_strlen(left_c) + ft_strlen(tmp)] = '\0';
	free(left_c);
	return (joined_str);
}
