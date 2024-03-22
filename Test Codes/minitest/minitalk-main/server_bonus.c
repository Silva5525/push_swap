/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:02:13 by lgaudin           #+#    #+#             */
/*   Updated: 2024/01/22 17:12:20 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	long	nbr;

	nbr = nb;
	if (nbr < 10)
	{
		ft_putchar(nbr + '0');
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

int	ft_atoi(char *str, int *res)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	*res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*res *= 10;
		*res += str[i] - '0';
		i++;
	}
	return (1);
}

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

pid_t	getpid(void);
void	ft_putchar(char c);
void	ft_putnbr(int nb);

pid_t	g_clientpid = -1;

void	rec(int n, int pid)
{
	int				shift;
	static int		i = 7;
	static char		c;

	if (i == -1 || pid != g_clientpid)
	{
		i = 7;
		c = 0;
		g_clientpid = pid;
	}
	shift = 1 << (i);
	if (n != 0)
		c = (c | shift);
	i--;
	if (i == -1)
	{
		write (1, &c, 1);
		if (c == 0)
			kill(g_clientpid, SIGUSR1);
	}
}

void	server(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
}

void	sig_handler(int sig, siginfo_t *info, void *ptr)
{
	(void)ptr;
	if (sig == SIGUSR1)
		rec(1, info->si_pid);
	else
		rec(0, info->si_pid);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = 0;
	act.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	server();
	while (1)
		pause();
	return (0);
}
