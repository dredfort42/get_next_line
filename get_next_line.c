#include "get_next_line.h"

/**
 * @brief Extracts the next line from the storage string.
 *
 * @param storage The storage string containing data read from the file descriptor.
 * @return A pointer to the newly allocated string containing the next line,
 *         or NULL on allocation failure.
 */
static char *next_line_from_storage(char *storage)
{
	size_t i;
	char *line;

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
static char *error(char *buffer)
{
	free(buffer);
	return (NULL);
}

/**
 * @brief Removes the extracted line from the storage string.
 *
 * @param storage The storage string containing data read from the file descriptor.
 * @return A pointer to the newly allocated string with the extracted line removed,
 *         or NULL if there is no remaining data.
 */
static char *remove_line_from_storage(char *storage)
{
	size_t i;
	size_t j;
	char *line;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
		error(storage);
	line = (char *)malloc(sizeof(char) * (ft_strlen(storage) - i));
	if (!line)
		error(storage);
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
char *get_next_line(int fd)
{
	char *buffer;
	char *line;
	static char *storage;
	ssize_t bytes_was_read;

	bytes_was_read = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || fd > sysconf(_SC_OPEN_MAX) || BUFFER_SIZE <= 0 || !buffer)
		return (error(buffer));
	while (!ft_strchr(storage, '\n') && bytes_was_read != 0)
	{
		bytes_was_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_was_read < 0)
			return (error(buffer));
		buffer[bytes_was_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	line = next_line_from_storage(storage);
	storage = remove_line_from_storage(storage);
	return (line);
}
