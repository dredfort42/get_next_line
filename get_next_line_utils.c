#include "get_next_line.h"

/**
 * @brief Calculates the length of a string.
 *
 * @param s The input string.
 * @return The length of the string.
 */
size_t ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * @brief Copies len bytes from src to dst, handling overlapping memory areas.
 *
 * @param dst The destination memory area.
 * @param src The source memory area.
 * @param len The number of bytes to copy.
 * @return A pointer to the destination memory area.
 */
void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	const unsigned char *s;
	size_t i;

	if (!dst || !src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d > s)
	{
		i = len;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

/**
 * @brief Joins two strings into a new string.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A pointer to the newly allocated string containing the concatenation
 *         of s1 and s2, or NULL on allocation failure.
 */
char *ft_strjoin(char const *s1, char const *s2)
{
	size_t len1;
	size_t len2;
	char *str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, len1);
	ft_memmove(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * @param s The string to be searched.
 * @param c The character to locate.
 * @return A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
