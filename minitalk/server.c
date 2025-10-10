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
void	sig_handler(int signum, siginfo_t *signal_info, void *context)
{
	//static var tracks which place of the bit the sig received corresponds
	//to
	static int	bit;
	static int	byte;
	char	character;

	//define character as 0 (defensive programming). Created character var in
	//order to be able to use write, which is simpler & faster than ft_printf
	character = 0;
	//use context to avoid compiler warning
	(void)context;
	//change current character bit to 1 if SIGUSR1 is received
	if (signum == SIGUSR1)
		byte |= (0x80 >> bit);
		//same as "character = character | (0x80 >> bit)". 0x80 has binary
		//code of 1000 0000, so shifting it bit places to right puts 1 in place
		//that corresponding to current bit
	bit++;
	//check if 8 bits have been received, if so, print char
	if (bit == 8)
	{
		character = (char)byte;
		write(1, &character, 1);//needed to use printf to interpret as char
		bit = 0;
		byte = 0;
	}
	//send a sig back to sending process to acknowledge reception, using
	//the si_pid var in the siginfo_t struct. Moving this down to end of 
	//func solved occasional print problems
	kill(signal_info->si_pid, SIGUSR1);
}

int	main(void)	
{
	//the struct format used by sigaction can by found in the man
	//use sigaction to be able to take into account more info than signal()
	struct sigaction	sig_received;

	//set sa_flags to SA_SIGINFO so sa_sigaction (& not sa_handler) is used.
	//sa_sigaction is a 3-arg handler, sa_handler only takes 1 arg.
	//The 2nd arg taken by sigaction, info, is a ptr to siginfo_t, a struct
	//w/ more info about the signal, including the sender's PID
	sig_received.sa_flags = SA_SIGINFO;
	//assign above func sig_handler to handle incoming signals by putting its
	//address in the sa_sigaction field of the sig_received struct
	sig_received.sa_sigaction = sig_handler;
	//set value of sa_mask in the sig_received struct to empty, b/c I don't
	//want any signals blocked, & if I don't set to empty it will contain
	//garbage values which could cause something to be blocked unintentionally
	sigemptyset(&sig_received.sa_mask);
	//get server PID & print it using my ft_printf function
	ft_printf("server PID: %i\n", getpid());
	//indicate handler designated in sig_received struct when x signal is 
	//received. 3rd param is ptr to ucontext_t struct w/ info about sig
	//context, which I'm not using, so I set it to NULL
	sigaction(SIGUSR1, &sig_received, NULL);
	sigaction(SIGUSR2, &sig_received, NULL);
	//create an infinite loop to keep the server running
	while (42)
	{

       	//keep prog running while waiting for a signal from the client
		pause();
	}
}
