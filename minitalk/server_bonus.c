/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:38:30 by wdegraf           #+#    #+#             */
/*   Updated: 2024/01/29 21:01:34 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

/// @param sigaction to see how its build... include in #include <signal.h>
/// The additional information provided to sig_do via the siginfo_t structure 
// can include details such as the PID of the sending process, the UID of the 
// sending process, and additional data about the signal.
/// signal with sig_do, which saves the bits and prints it. after sending back
/// the signal recieved.
/// struct sigaction 
/// {
///   void     (*sa_handler)(int);
///    void     (*sa_sigaction)(int, siginfo_t *, void *);
///    sigset_t   sa_mask;
///    int        sa_flags;
///    void     (*sa_restorer)(void);
/// };
///
/// @brief gets the pid and a char and sends the char bit by bit to the client
/// if (hold % 2 == 0) is true the bit is 0 and sends SIGUSR2 using kill..
/// else its 1 and sends SIGUSR1 using kill.. if kill fails it exits with 1..
/// hold = c >> i shifts the char to the right so the LSB is the first bit 
/// to be sent. ( LSB = Least Significant Bit ) ( MSB = Most Significant Bit )
/// @param si_pid from the client
/// @param c the char to send
/// @param hold the hold for the bit so it can be shifted
void	sig_c(siginfo_t *info, unsigned char c)
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
			if (kill(info->si_pid, SIGUSR2) == -1)
				exit(1);
		}
		else
			if (kill(info->si_pid, SIGUSR1) == -1)
				exit(1);
	}
}

/// @brief takes the given signnal by checking if signal == SIGUSR1 
/// if true = 1 else = 0 saves with |= and collects the bits till 8 bits are 
/// collected. then it saves it in str and resets the bit counter (bit_i) 
/// and the char (hold_c) after each bit saves it shifts the char to the left.
/// Calls sig_c to send the signal back to the client.
/// @param signal is a bit of 1 if SIGUSR1 or 0 if SIGUSR2
/// @param info is the struct siginfo_t which contains the pid of the client
/// @param ucontext is not used but needed for sigaction
void	sig_do(int signal, siginfo_t *info, void *ucontext)
{
	static unsigned char	hold_c;
	static int				bit_i;
	static unsigned char	str[1001];
	static int				i;

	(void)ucontext;
	hold_c |= (signal == SIGUSR1);
	bit_i++;
	if (bit_i == 8)
	{
		if (hold_c == '\0')
			str[i++] = '\n';
		else
			str[i++] = hold_c;
		sig_c(info, hold_c);
		bit_i = 0;
		hold_c = 0;
		if (i == 1000 || str[i - 1] == '\n')
		{
			write(1, str, i);
			i = 0;
		}
	}
	else
		hold_c <<= 1;
}

/// @brief sends the pid for the client and waits for a signal
/// sigaction is used to handle the signal. si.sa_sigaction = &sig_do;
/// means that sig_do is called when a signal is received.
/// sig_flags = SA_SIGINFO saves aditional information about the signal
/// sigemptyset(&si.sa_mask); is used to empty the mask so no other signal
/// is blocked. sigaction(SIGUSR1, &si, NULL); gives the signal to sigaction1 
/// &si is the struct with the pid and the function to call. NULL is just
/// a filler for ucontext which is not used.
/// @return 0 if everything is ok
int	main(void)
{
	pid_t					pid;
	char					*cpid;
	struct sigaction		si;

	pid = getpid();
	if (pid == -1)
		return (1);
	cpid = ft_itoa(pid);
	if (!cpid)
		return (1);
	write(1, cpid, ft_strlen(cpid));
	free(cpid);
	write(1, "\n", 1);
	si.sa_sigaction = &sig_do;
	si.sa_flags = SA_SIGINFO;
	sigemptyset(&si.sa_mask);
	sigaction(SIGUSR1, &si, NULL);
	sigaction(SIGUSR2, &si, NULL);
	while (1)
		pause();
	return (0);
}
