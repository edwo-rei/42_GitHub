/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:59:45 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/16 17:44:37 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*include guard protects against double inclusion, first line checks if .h file
  already defined. If not defined, 2nd line says to define it*/
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
//stdarg library includes variable that allows for indefinite # of args
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);

#endif
