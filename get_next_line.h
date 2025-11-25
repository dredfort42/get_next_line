#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

size_t ft_strlen(const char *s);
void *ft_memmove(void *dst, const void *src, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchr(const char *s, int c);
int get_next_line(int fd, char **line);
int error(char *buffer);
char *next_line_from_storage(char *storage);
char *remove_line_from_storage(char *storage);

#endif
