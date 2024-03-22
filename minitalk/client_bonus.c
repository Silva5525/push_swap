/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:38:56 by wdegraf           #+#    #+#             */
/*   Updated: 2024/01/29 15:04:12 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

/// @brief gets the pid and a char and sends the char bit by bit to the client
/// hold = c >> i shifts the char to the right so the LSB is the first bit 
/// to be sent. ( LSB = Least Significant Bit ) ( MSB = Most Significant Bit )
/// if (hold % 2 == 0) is true the bit is 0 and sends SIGUSR2 using kill..
/// else its 1 and sends SIGUSR1 using kill.. if kill fails it exits with 1..
/// @param pid from the server
/// @param c the char to send
/// @param hold the hold for the bit so it can be shifted
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
		usleep(50);
	}
}

/// @brief gets accnowledgement from the server and prints it
/// @param sig the signal from the server
void	sig_back(int sig)
{
	if (sig == SIGUSR1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	usleep(25);
}

/// @brief Takes the given pid and a message and sends it to the server
///  by calling sig_c for each char in the message and sending a '\0' for end.
/// @param argc argc[0] = ./client argc[1] = pid argc[2] = message
/// @param argv argv[1] = s_pid argv[2] = str
/// @return 0 if successfull
int	main(int argc, char *argv[])
{
	pid_t			s_pid;
	const char		*str;
	int				i;

	signal(SIGUSR1, sig_back);
	signal(SIGUSR2, sig_back);
	if (argc != 3)
	{
		write(1, "Write: ./client_bonus <pid> <messege>\n", 39);
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
