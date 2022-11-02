/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:48:21 by lsabik            #+#    #+#             */
/*   Updated: 2022/10/27 23:48:23 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

#define FLAGS_PLUS  1
#define FLAGS_HASH  2
#define FLAGS_SPACE 4

static void	ft_doprint(char format, va_list arg, int *count)
{
	if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(arg, int), count);
	else if (format == 'c')
		ft_putchar(va_arg(arg, int), count);
	else if (format == 's')
		ft_putstr(va_arg(arg, char *), count);
	else if (format == 'u')
		ft_putnbr_u(va_arg(arg, unsigned int), count);
	else if (format == 'x')
		ft_putnbr_hexa(va_arg(arg, unsigned int), count, format);
	else if (format == 'X')
		ft_putnbr_hexa(va_arg(arg, unsigned int), count, format);
	else if (format == 'p')
		ft_putaddr(va_arg(arg, unsigned long long), count);
	else if (format == '\0')
		return ;
	else
		ft_putchar(format, count);
}

char	*check_flags(char *format, va_list arg, int *count)
{
	int		flag_checker;

	flag_checker = 0;
	while (*format == '#' || *format == ' ' || *format == '+')
	{
		if (*format == '#')
			flag_checker |= FLAGS_HASH;
		else if (*format == ' ')
			flag_checker |= FLAGS_SPACE;
		else if (*format == '+')
			flag_checker |= FLAGS_PLUS;
		format++;
	}	
	if ((*format == 'x' || *format == 'X') && (flag_checker & FLAGS_HASH))
		hashtag_flag(*format, arg, count);
	else if ((*format == 'd' || *format == 'i') && (flag_checker & FLAGS_PLUS))
		plus_flag(va_arg(arg, int), count);
	else if ((*format == 'd' || *format == 'i') && (flag_checker & FLAGS_SPACE))
		space_flag(va_arg(arg, int), count);
	else if (*format == 's' && ((flag_checker & FLAGS_SPACE)
			|| (flag_checker & FLAGS_PLUS) || (flag_checker & FLAGS_HASH)))
		ft_putstr(va_arg(arg, char *), count);
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '#' || *format == ' ' || *format == '+')
				format = check_flags((char *)&(*format), arg, &count);
			else
				ft_doprint(*format, arg, &count);
		}
		else
			ft_putchar(*format, &count);
		if (*format)
			format++;
	}
	va_end(arg);
	return (count);
}
