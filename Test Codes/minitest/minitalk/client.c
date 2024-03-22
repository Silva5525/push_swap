/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:38:56 by wdegraf           #+#    #+#             */
/*   Updated: 2024/01/22 16:32:13 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

void	sig_c(int pid, unsigned char c)
{
	int				i;
	unsigned char	hold;

	i = 8;
	hold = c;
	while (i > 0)
	{
		i--;
		hold = c >> i;
		if (hold % 2 == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		usleep(400);
	}
}

int	main(int argc, char *argv[])
{
	pid_t			s_pid;
	const char		*str;
	int				i;

	if (argc != 3)
	{
		write(1, "Write: ./client <pid> <messege>", 32);
		exit(0);
	}
	s_pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i])
		sig_c(s_pid, str[i++]);
	sig_c(s_pid, '\0');
	return (0);
}