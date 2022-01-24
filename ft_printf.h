/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taliza <taliza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:33:33 by taliza            #+#    #+#             */
/*   Updated: 2021/12/28 16:27:36 by taliza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<unistd.h>
# include	<stdarg.h>

int		ft_printf(const char *s, ...);
void	format_check(int *l, va_list ap, const char *s, int *i);
void	ft_puthex(int *len, unsigned int num, char *base, int num_base);
void	ft_putstr(int *l, char *s);
void	ft_putnbr(int *l, int n);
void	ft_putptr(int *l, unsigned long nbr, char *base, int flag);
void	ft_putchar(int *l, char c);

#endif
