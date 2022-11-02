/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:32:06 by lsabik            #+#    #+#             */
/*   Updated: 2022/10/29 12:32:10 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	hashtag_flag(char format, va_list arg, int *count)
{
	unsigned int	n;

	n = va_arg(arg, unsigned int);
	if (n == 0)
		ft_putstr ("0", count);
	else if (format == 'x')
		ft_putaddr (n, count);
	else if (format == 'X')
	{
		ft_putstr ("0X", count);
		ft_putnbr_hexa (n, count, 'X');
	}
}

void	space_flag(int i, int *count)
{
	if (i >= 0)
	{
		ft_putchar(' ', count);
		ft_putnbr(i, count);
	}
	else
		ft_putnbr(i, count);
}

void	plus_flag(int i, int *count)
{
	if (i >= 0)
	{
		ft_putchar('+', count);
		ft_putnbr(i, count);
	}
	else
		ft_putnbr(i, count);
}
