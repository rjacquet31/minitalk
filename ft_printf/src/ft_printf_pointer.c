/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 06:21:14 by rafael            #+#    #+#             */
/*   Updated: 2025/02/11 06:21:14 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printf_pointer(va_list *arg)
{
	unsigned long	nb;
	int				count;

	nb = va_arg(*arg, unsigned long);
	count = ft_count_hexa(nb);
	ft_putstr_fd("0x", 1);
	ft_puthexa_fd(nb, 'x', 1);
	return (count + 2);
}
