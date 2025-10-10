/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:01:30 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/10/02 17:36:36 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//use global flag variable to acknowledge reception of sig by server
//"volatile" means it can change at any time, warns compiler not to optimize
//out checks of global var. sig_atomic_t is a special type of int that is read
//"atomically", meaning in 1 uninterruptible operation - so the CPU can't be 
// interrupted while reading by an update to the variable
volatile sig_atomic_t	g_copy = 0;

//function to handle acknowledgement sig sent by server and change value of 
//g_acknowledge to 1 when received
void	serv_sig_handler(int signum)
{
	(void)signum;
	g_copy = 1;
}

//read each char in binary and sent it to server bit by bit, pause for 
//acknowledgement after each char sent
void	send_sig(int pid, char c)
{
	//i will determine the # of places we shift the 8-digit binary code for the 
	//char to the right
	int	i;

	//start with the most signficant bit (MSB)
	i = 7;
	while (i >= 0)
	{
		//shift given bit i places to right. If 1, "& 1" mask will meet if
		//condition, & SIGUSR1 will be sent to server
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		//If 0, SIGUSR2 is sent to server
		else
			kill(pid, SIGUSR2);
		//removed usleep delay b/c unneeded w/ global var check
		//wait for server acknowldegement after a char's worth of bits sent
		//removed pause() command b/c unneeded & concern that it could be
		//complicating operation
		while (!g_copy)
			;
		//reset g_copy to 0 once changed to 1 (reception confirmed)
		g_copy = 0;
		//repeat same process shifting one less place to the right
		i--;
	}
}

//client will take server PID & message as args
int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	
	i = 0;
	if (argc == 3)
	{
		// convert PID to int
		pid = ft_atoi(argv[1]);
		//inform OS that serv_sig_handler func should be called when client
		//receives SIGUSR1
		signal(SIGUSR1, serv_sig_handler);
		// call send_sig func for each char
		while (argv[2][i])
		{
			send_sig(pid, argv[2][i]);
			i++;
		}
		//send \n after all chars sent
		send_sig(pid, '\n');
	}
	//print error if anything besides 2 ars received
	else
		ft_printf("Error\n");
}
