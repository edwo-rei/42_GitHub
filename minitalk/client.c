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

//read each char in binary and sent it to server bit by bit
void	send_sig(int pid, char c)
{
	//i will determine the # of places we shift the 8-digit binary code for the 
	//char to the right
	int	i;

	//start with the MSB
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
		//cause a 100 microsecond delay in b/t bits so they are received well
		usleep(100);
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
		// call send_sig func for each char
		while (argv[2][i])
		{
			send_sig(pid, argv[2][i]);
			i++;
		}
		//send something (e.g., \n) after message?
	}
	else
		ft_printf("Error\n");
}
