/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:49:49 by lsabik            #+#    #+#             */
/*   Updated: 2022/10/27 23:49:52 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

void	ft_putnbr_u(unsigned int num, int *count)
{
	char		c;

	if (num / 10 != 0)
		ft_putnbr (num / 10, count);
	c = (num % 10) + 48;
	ft_putchar (c, count);
}
