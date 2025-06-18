/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:18:12 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/06/18 17:27:21 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*include guard protects against double inclusion, first line checks if .h file
  already defined. If not defined, 2nd line says to define it*/
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//NOT WORKING:define a buffer size if no buffer size is defined at compilation
//try adding a space after each pound symbol?
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 25
#endif

//stdlib contains malloc & free
# include <stdlib.h>
//unistd library contains write & read
# include <unistd.h>
//fcntl library includes open, needed for testing, not sure if allowed
# include <fcntl.h>
//stdio library contains printf, which I'll use for testing
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif
