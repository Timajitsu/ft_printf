/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taliza <taliza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:33:28 by taliza            #+#    #+#             */
/*   Updated: 2021/12/28 16:45:19 by taliza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			i;
	int			l;

	if (!s)
		return (-1);
	va_start(ap, s);
	i = 0;
	l = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '%' && s[i + 1])
			format_check(&l, ap, s, &i);
		else
		{
			if (s[i] == '%' && s[i + 1] == '%')
				i++;
			write(1, &s[i], 1);
			i++;
			l++;
		}
	}
	return (l);
	va_end(ap);
}

void	format_check(int *l, va_list ap, const char *s, int *i)
{
	if (s[*i + 1] == 's')
		ft_putstr(l, va_arg(ap, char *));
	else if (s[*i + 1] == 'c')
		ft_putchar(l, va_arg(ap, int));
	else if (s[*i + 1] == 'p')
		ft_putptr(l, va_arg(ap, unsigned long), "0123456789abcdef", 1);
	else if (s[*i + 1] == 'd' || s[*i + 1] == 'i')
		ft_putnbr(l, va_arg(ap, int));
	else if (s[*i + 1] == 'u')
		ft_puthex(l, va_arg(ap, unsigned int), "0123456789", 10);
	else if (s[*i + 1] == 'x')
		ft_puthex(l, va_arg(ap, unsigned int), "0123456789abcdef", 16);
	else if (s[*i + 1] == 'X')
		ft_puthex(l, va_arg(ap, unsigned int), "0123456789ABCDEF", 16);
	else if (s[*i + 1] != 's' && s[*i + 1] != 'c' && s[*i + 1] != 'p'
		&& s[*i + 1] != 'd' && s[*i + 1] != 'i' && s[*i + 1] != 'u'
		&& s[*i + 1] != 'x' && s[*i + 1] != 'X')
	{
		write(1, &s[*i + 1], 1);
		l += 1;
	}
	*i += 2;
}
