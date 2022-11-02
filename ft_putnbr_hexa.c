/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:49:49 by lsabik            #+#    #+#             */
/*   Updated: 2022/10/27 23:49:52 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	long long	num;
	char		c;

	num = n;
	if (num < 0)
	{
		num *= -1;
		ft_putchar ('-', count);
	}
	if (num / 10 != 0)
		ft_putnbr (num / 10, count);
	c = (num % 10) + 48;
	ft_putchar(c, count);
}

void	ft_putnbr_hexa(unsigned long int num, int *count, char up_low)
{
	char	*base;

	if (up_low == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num / 16 != 0)
	{
		ft_putnbr_hexa (num / 16, count, up_low);
		ft_putnbr_hexa (num % 16, count, up_low);
	}
	if (num < 16)
		ft_putchar (base[num % 16], count);
}
