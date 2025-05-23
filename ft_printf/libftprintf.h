/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:59:45 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/16 19:40:30 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*include guard protects against double inclusion, first line checks if .h file
  already defined. If not defined, 2nd line says to define it*/
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
//stdarg library includes variable that allows for indefinite # of args
# include <stdarg.h>
//stdlib contains malloc & free
# include <stdlib.h>
//unistd library contains write
# include <unistd.h>
//stdio library contains the established printf, which I'll compare to my printf
# include <stdio.h>

int		ft_printf(const char *s, ...);

#endif
