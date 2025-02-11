/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 06:20:09 by rafael            #+#    #+#             */
/*   Updated: 2025/02/11 06:20:09 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printf_hexa(char var, va_list *arg)
{
	unsigned int	nb;
	int				count;

	nb = va_arg(*arg, unsigned int);
	count = ft_count_hexa(nb);
	ft_puthexa_fd(nb, var, 1);
	return (count);
}
