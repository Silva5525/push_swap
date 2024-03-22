/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:38:30 by wdegraf           #+#    #+#             */
/*   Updated: 2024/01/22 12:15:33 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void	sig_handle(int signal)
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

int	main(void)
{
	pid_t 	pid;
	char	*cpid;

	pid = getpid();
	cpid = ft_itoa(pid);
	if (!cpid)
		return (1);
	write(1, cpid, ft_strlen(cpid));
	free(cpid);
	write(1, "\n", 1);
	signal(SIGUSR1, sig_handle);
	signal(SIGUSR2, sig_handle);
	while (1)
		pause();
	return (0);
}