/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:38:30 by wdegraf           #+#    #+#             */
/*   Updated: 2024/01/29 21:02:10 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

/// @brief takes the given signnal by checking if signal == SIGUSR1 
/// if true = 1 else = 0 saves with |= and collects the bits till 8 bits are 
/// collected then it prints out the char and resets the bit counter (bit_i) 
/// and the char (hold_c) after each bit savesit shifts the char to the left.
/// @param signal is a bit of 1 if SIGUSR1 or 0 if SIGUSR2
void	sig_do(int signal)
{
	static unsigned char	hold_c;
	static int				bit_i;

	hold_c |= (signal == SIGUSR1);
	bit_i++;
	if (bit_i == 8)
	{
		if (hold_c == '\0')
			write(1, "\n", 1);
		else
			write(1, &hold_c, 1);
		bit_i = 0;
		hold_c = 0;
	}
	else
		hold_c <<= 1;
}

/// @brief the server generetes a pid and prints it out
/// then it waits for a signal and callls sig_handle to handle the signal
/// @param  signal of SIGUSR1 or SIGUSR2
/// @return will never reached
int	main(void)
{
	pid_t	pid;
	char	*cpid;

	pid = getpid();
	if (pid < 0)
		return (1);
	cpid = ft_itoa(pid);
	if (!cpid)
		return (1);
	write(1, cpid, ft_strlen(cpid));
	free(cpid);
	write(1, "\n", 1);
	signal(SIGUSR1, sig_do);
	signal(SIGUSR2, sig_do);
	while (1)
		pause();
	return (0);
}
