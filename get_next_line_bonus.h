/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovikov <dnovikov@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:44:05 by dnovikov          #+#    #+#             */
/*   Updated: 2025/12/15 19:05:05 by dnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// Define buffer size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif // BUFFER_SIZE

// Define maximum number of file descriptors to handle
# ifndef MAX_PROCESS_FD
#  define MAX_PROCESS_FD 1024
# endif // MAX_PROCESS_FD

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif // GET_NEXT_LINE_BONUS_H
