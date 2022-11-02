/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:49:09 by lsabik            #+#    #+#             */
/*   Updated: 2022/10/27 23:49:11 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

void	ft_putaddr(unsigned long long n, int *count)
{
	ft_putstr ("0x", count);
	ft_putnbr_hexa (n, count, 'x');
}
