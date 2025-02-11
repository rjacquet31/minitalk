/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 06:17:16 by rafael            #+#    #+#             */
/*   Updated: 2025/02/11 06:17:16 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

int		ft_count_nbr(int nb);
int		ft_count_nbr_unsigned(unsigned int nb);
int		ft_count_hexa(unsigned int nb);

int		ft_printf_char(va_list *arg);
int		ft_printf_str(va_list *arg);
int		ft_printf_pointer(va_list *arg);
int		ft_printf_number(va_list *arg);
int		ft_printf_unsigned_number(va_list *arg);
int		ft_printf_hexa(char var, va_list *arg);

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_puthexa_fd(unsigned int nb, char var, int fd);
size_t	ft_strlen(const char *s);

#endif