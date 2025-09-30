/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:50:20 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/22 12:14:55 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*include guard protects against double inclusion, first line checks if .h file
  already defined. If not defined, 2nd line says to define it*/
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//stdarg library includes variable that allows for indefinite # of args
# include <stdarg.h>
//unistd library contains write
# include <unistd.h>
//stdint library contains value type uintptr_t, used for pointers
# include <stdint.h>
/*stdio library contains the established printf, which I'll compare to my printf
# include <stdio.h>*/

int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printint(int n);
int		ft_printunint(unsigned int n);
int		ft_printhex(unsigned int n, char c);
int		ft_printptr(uintptr_t ptr);

#endif
