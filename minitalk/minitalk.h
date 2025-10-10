/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:42:05 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/09/30 14:20:10 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* INCLUDE GUARD */
#ifndef MINITALK_H
# define MINITALK_H

/* LIBRARIES */
//stdlib contains malloc, free & exit
# include <stdlib.h>
//unistd library contains write, getpid & pause
# include <unistd.h>
//stdio library contains printf, which I'll use for testing
# include <stdio.h>
//signal library contains signal functions
# include <signal.h>

/* MY HEADER FILES */
//libft header file contains the prototypes of my libft functions
# include "libft/libft.h"
//ft_printf header file contains prototypes of my ft_printf functions
# include "ft_printf/ft_printf.h"

#endif
