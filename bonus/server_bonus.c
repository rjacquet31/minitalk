/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:00:25 by rafael            #+#    #+#             */
/*   Updated: 2025/02/24 12:00:25 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

void	sig_reception(int sig)
{
	static int				count_bits = 0;
	static unsigned char	current_byte = 0;

	if (sig == SIGUSR1)
		current_byte = (current_byte << 1) | 0;
	else if (sig == SIGUSR2)
		current_byte = (current_byte << 1) | 1;
	count_bits++;
	if (count_bits == 8)
	{
		write(1, &current_byte, 1);
		count_bits = 0;
		current_byte = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = sig_reception;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
