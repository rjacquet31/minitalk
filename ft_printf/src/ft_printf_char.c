/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 06:19:08 by rafael            #+#    #+#             */
/*   Updated: 2025/02/11 06:19:08 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printf_char(va_list *arg)
{
	char	c;

	c = va_arg(*arg, int);
	ft_putchar_fd(c, 1);
	return (1);
}
