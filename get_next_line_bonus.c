/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovikov <dnovikov@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:44:39 by dnovikov          #+#    #+#             */
/*   Updated: 2025/12/14 18:01:55 by dnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief Extracts the next line from the storage string.
 *
 * @param storage The storage string containing data read
 *                from the file descriptor.
 * @return A pointer to the newly allocated string containing the next line,
 *         or NULL on allocation failure.
 */
static char	*next_line_from_storage(char *storage)
{
	size_t	i;
	char	*line;

	if (!storage || !*storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/**
 * @brief Handles errors by freeing the buffer and returning NULL.
 *
 * @param buffer The buffer to free.
 * @return NULL.
 */
static char	*error(char *buffer)
{
	if (buffer)
		free(buffer);
	return (NULL);
}

/**
 * @brief Reads from fd and appends to storage.
 *
 * @param fd The file descriptor to read from.
 * @param storage A pointer to the storage string.
 * @param buffer The buffer for reading.
 * @return 0 on success, -1 on error.
 */
static int	read_to_storage(int fd, char **storage, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (!ft_strchr(*storage, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*storage, buffer);
		if (!temp)
			return (-1);
		free(*storage);
		*storage = temp;
	}
	return (0);
}

/**
 * @brief Removes the extracted line from the storage string.
 *
 * @param storage The storage string containing data read
 *                from the file descriptor.
 * @return A pointer to the newly allocated string with
 *         the extracted line removed, or NULL if there is
 *         no remaining data.
 */
static char	*remove_line_from_storage(char *storage)
{
	size_t	i;
	size_t	j;
	char	*line;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
		return (error(storage));
	line = (char *)malloc(sizeof(char) * (ft_strlen(storage) - i));
	if (!line)
		return (error(storage));
	i++;
	j = 0;
	while (storage[i])
		line[j++] = storage[i++];
	line[j] = '\0';
	free(storage);
	return (line);
}

/**
 * @brief Reads a line from a file descriptor and returns it as a string.
 *
 * @param fd The file descriptor to read from.
 * @return A pointer to the read line, or NULL on error or end of file.
 */
char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*storage[MAX_PROCESS_FD];

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || fd > MAX_PROCESS_FD || BUFFER_SIZE <= 0 || !buffer)
		return (error(buffer));
	if (!storage[fd])
	{
		storage[fd] = (char *)malloc(1);
		if (!storage[fd])
			return (error(buffer));
		(storage[fd])[0] = '\0';
	}
	if (read_to_storage(fd, &storage[fd], buffer) == -1)
		return (error(buffer));
	free(buffer);
	line = next_line_from_storage(storage[fd]);
	storage[fd] = remove_line_from_storage(storage[fd]);
	return (line);
}
