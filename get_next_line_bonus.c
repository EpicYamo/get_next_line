/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:34:50 by aaycan            #+#    #+#             */
/*   Updated: 2025/09/01 18:37:07 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

static char	*ft_set_left_characters(int fd, char *left_c);
static char	*ft_create_output_line(char *left_c);
static char	*ft_update_left_characters(char *left_c);
static char	*ft_validate_variables_and_join(char *left_c, char *tmp);

char	*get_next_line(int fd)
{
	char		*output_line;
	static char	*left_c[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(left_c[fd]);
		return (NULL);
	}
	left_c[fd] = ft_set_left_characters(fd, left_c[fd]);
	if (!left_c[fd])
		return (NULL);
	output_line = ft_create_output_line(left_c[fd]);
	left_c[fd] = ft_update_left_characters(left_c[fd]);
	return (output_line);
}

static char	*ft_set_left_characters(int fd, char *left_c)
{
	int		read_bytes;
	char	*tmp;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
	{
		free(left_c);
		return (NULL);
	}
	read_bytes = 1337;
	while (read_bytes != 0 && !ft_check_newline_existence(left_c))
	{
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(left_c);
			free(tmp);
			return (NULL);
		}
		tmp[read_bytes] = '\0';
		left_c = ft_validate_variables_and_join(left_c, tmp);
	}
	free(tmp);
	return (left_c);
}

static char	*ft_create_output_line(char *left_c)
{
	char	*line;
	int		i;

	i = 0;
	if (!left_c[i])
		return (NULL);
	if (ft_strchr(left_c, '\n'))
		line = malloc(ft_count_to_end_of_line(left_c) + 2);
	else
		line = malloc(ft_count_to_end_of_line(left_c) + 1);
	if (!line)
	{
		free(left_c);
		return (NULL);
	}
	i = -1;
	while (left_c[++i] != '\n' && left_c[i] != '\0')
		line[i] = left_c[i];
	if (left_c[i] == '\n')
	{
		line[i] = left_c[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_update_left_characters(char *left_c)
{
	char	*updated_left_c;
	int		i;
	int		j;

	i = ft_count_to_end_of_line(left_c);
	if (!left_c[i] && left_c)
	{
		free(left_c);
		return (NULL);
	}
	updated_left_c = malloc(ft_strlen(left_c) - i + 1);
	if (!updated_left_c)
	{
		free(left_c);
		return (NULL);
	}
	i++;
	j = 0;
	while (left_c[i])
		updated_left_c[j++] = left_c[i++];
	updated_left_c[j] = '\0';
	free(left_c);
	return (updated_left_c);
}

static char	*ft_validate_variables_and_join(char *left_c, char *tmp)
{
	char	*joined_str;

	if (!left_c)
	{
		left_c = malloc(1);
		left_c[0] = '\0';
	}
	if (!left_c || !tmp)
		return (NULL);
	joined_str = ft_strjoin_modified(left_c, tmp);
	return (joined_str);
}
