/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedogan <nedogan@42istanbul.student.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:51:40 by nedogan           #+#    #+#             */
/*   Updated: 2025/08/12 11:53:16 by nedogan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*fft_strjoin(char *s1, char *s2);
char	*fft_strchr(char *s, int c);
size_t	fft_strlen(char *s);
char	*fft_substr(char *s, unsigned int start, size_t len);
char	*fft_strdup(char *s);

#endif
