/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:03:00 by lsabik            #+#    #+#             */
/*   Updated: 2022/10/27 23:48:41 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include<stdarg.h>
# include<stdlib.h>
# include<unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putnbr_hexa(unsigned long int n, int *count, char format);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putaddr(unsigned long long n, int *count);
void	hashtag_flag(char format, va_list arg, int *count);
void	space_flag(int i, int *count);
void	plus_flag(int i, int *count);
void	ft_putnbr_u(unsigned int num, int *count);
#endif
