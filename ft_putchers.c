/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taliza <taliza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:25:56 by taliza            #+#    #+#             */
/*   Updated: 2021/12/28 16:34:46 by taliza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int *l, char c)
{
	*l += 1;
	write(1, &c, 1);
}

void	ft_putstr(int *l, char *s)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
		*l += i;
	}
	else
	{
		write(1, "(null)", 6);
		*l += 6;
	}
}

void	ft_putnbr(int *l, int n)
{
	char	num;

	num = '-';
	if (n < 0)
	{
		write(1, &num, 1);
		*l += 1;
		if (n == -2147483648)
		{
			num = '2';
			write(1, &num, 1);
			*l += 1;
			n = 147483648;
		}
		else
			n = -n;
	}
	while (n / 10 > 0)
	{
		ft_putnbr(l, n / 10);
		n = n % 10;
	}
	num = n + '0';
	write(1, &num, 1);
	*l += 1;
}

void	ft_putptr(int *l, unsigned long nbr, char *base, int flag)
{
	char	ch;

	if (flag)
	{
		write(1, "0x", 2);
		*l += 2;
	}
	while (nbr / 16 > 0)
	{
		ft_putptr(l, nbr / 16, base, 0);
		nbr %= 16;
	}
	*l += 1;
	ch = base[nbr % 16];
	write(1, &ch, 1);
}

void	ft_puthex(int *l, unsigned int num, char *base, int num_base)
{
	char	c;

	c = '0';
	if (num == 0)
	{
		write(1, &c, 1);
		*l += 1;
	}
	else
	{
		while (num / num_base > 0)
		{
			ft_puthex(l, num / num_base, base, num_base);
			num %= num_base;
		}
		*l += 1;
		c = base[num % num_base];
		write(1, &c, 1);
	}
}
