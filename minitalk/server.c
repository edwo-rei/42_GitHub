/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:02:09 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/10/03 15:04:31 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//reconvert signals, received as binary, into chars, & write them
void	sig_handler(int signum)
{
	//static var tracks which place of the bit the sig received corresponds
	//to
	static int	bit;
	static int	character;

	if (signum == SIGUSR1)
		character |= (0x80 >> bit);
		//same as "character = character | (0x80 >> bit)". 0x80 has binary
		//code of 1000 0000, so shifting it bit places to right puts 1 in place
		//that corresponding to current bit
	bit++;
	//check if 8 bits have been received, if so, print char
	if (bit == 8)
	{
		ft_printf("%c", character);//necessary to use printf to interpret as char?
		bit = 0;
		character = 0;
	}
}

int	main(void)	
{
	//the struct format used by sigaction can by found in the man
	//struct sigaction	sig_received; - NOT NECESSARY?

	//get server PID & print it using my ft_printf function
	ft_printf("server PID: %i\n", getpid());
	//handle incoming signals from client
	//sig_received.sa_handler - NOT NECESSARY?
	//create an infinite loop to keep the server running
	while (42)
	{
		//signal func indicates handler when x signal is received
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
       		//keep prog running while waiting for a signal from the client
		pause();
	}
}
