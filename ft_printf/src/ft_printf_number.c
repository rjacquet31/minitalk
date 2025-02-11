/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 06:20:36 by rafael            #+#    #+#             */
/*   Updated: 2025/02/11 06:20:36 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printf_number(va_list *arg)
{
	int	nb;
	int	count;

	nb = va_arg(*arg, int);
	count = ft_count_nbr(nb);
	ft_putnbr_fd(nb, 1);
	return (count);
}
