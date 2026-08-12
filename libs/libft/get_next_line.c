/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:29:47 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/27 16:54:17 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// THIS FUNCITON CLEAN US THE BUFFER, FREES THE LINE AND SETS IT TO NULL
int	clean_up(char **line, char *buffer)
{
	ft_bzero(buffer, BUFFER_SIZE + 1);
	free(*line);
	*line = NULL;
	return (1);
}

// THIS FUNCTION ALLOCATES THE NEW STRING AND FREES THE OLD ONE
int	redo_line(char **dst, char *src)
{
	char	*new;

	new = ft_strjoin(*dst, src);
	if (new == NULL)
		return (1);
	free(*dst);
	*dst = new;
	return (0);
}

// THIS FUNCTION WRITES THE REMAINING CHARS AFTER THE \N TO BUFFER
char	*get_new_buffer(char *line, char **buffer)
{
	char	*temp;
	int		i;

	i = 0;
	ft_bzero(*buffer, BUFFER_SIZE + 1);
	temp = ft_strchr(line, '\n');
	if (temp == NULL)
		return (*buffer);
	temp++;
	while (temp[i])
	{
		(*buffer)[i] = temp[i];
		i++;
	}
	(*buffer)[i] = '\0';
	return (*buffer);
}

// THIS FUNCITON IS THE MAIN PART IT PROCESSES UNTIL THE NEW LINE OR END
int	get_new_line(int fd, char **line, char *buffer)
{
	int		bytes;
	char	*end;

	bytes = 1;
	if (redo_line(&(*line), buffer))
		return (clean_up(&(*line), buffer));
	ft_bzero(buffer, BUFFER_SIZE + 1);
	end = ft_strchr(*line, '\n');
	while (bytes != 0 && !end)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (clean_up(&(*line), buffer));
		buffer[bytes] = '\0';
		if (redo_line(line, buffer))
			return (clean_up(&(*line), buffer));
		end = ft_strchr(*line, '\n');
	}
	buffer = get_new_buffer(*line, &buffer);
	if (end)
		ft_bzero(end + 1, ft_strlen(end + 1));
	return (redo_line(line, NULL), 0);
}

// THIS IS THE MAIN FUNCTION IT JUST CALLS THE REST
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		return (NULL);
	}
	line = malloc(1);
	if (!line)
		return (clean_up(&line, buffer), NULL);
	line[0] = '\0';
	if (get_new_line(fd, &line, buffer))
		return (NULL);
	if (line[0] == '\0')
		return (clean_up(&line, buffer), NULL);
	return (line);
}
