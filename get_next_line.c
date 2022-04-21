#include "get_next_line.h"

char	*next_line_from_storage(char *storage)
{
	int		i;
	char	*tmp;

	if (!storage)
		return (0);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		tmp[i] = storage[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*remove_line_from_storage(char *storage)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!storage)
		return (0);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (0);
	}
	tmp = malloc(sizeof(char) * ((ft_strlen(storage) - i) + 1));
	if (!tmp)
		return (0);
	i++;
	while (storage[i])
		tmp[j++] = storage[i++];
	tmp[j] = '\0';
	free(storage);
	return (tmp);
}

int	error(char *buffer)
{
	free(buffer);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*storage;
	int				bytes_was_read;

	bytes_was_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || fd > 1024 || !line || BUFFER_SIZE <= 0 || !buffer)
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
	*line = next_line_from_storage(storage);
	storage = remove_line_from_storage(storage);
	if (!bytes_was_read)
		return (0);
	return (1);
}
