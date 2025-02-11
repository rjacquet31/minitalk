/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 06:14:49 by rafael            #+#    #+#             */
/*   Updated: 2025/02/11 06:14:49 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

void	sig_reception(int sig)
{
	static int				count_bits;
	static unsigned char	current_byte;

	if (count_bits == 0)
		count_bits = 0;
	if (sig == SIGUSR1)
	{
		current_byte = (current_byte << 1) | 0;
		count_bits++;
	}
	else if (sig == SIGUSR2)
	{
		current_byte = (current_byte << 1) | 1;
		count_bits++;
	}
	if (count_bits > 7)
	{
		ft_printf("%c", current_byte);
		count_bits = 0;
		current_byte = 0;
	}
}

int	main(void)
{
	ft_printf("Tera Dev Server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, sig_reception);
		signal(SIGUSR1, sig_reception);
		pause();
	}
	return (0);
}
