/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:51:46 by cbourre           #+#    #+#             */
/*   Updated: 2022/04/25 16:59:03 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_decnbr(size_t n, int *ptr)
{
	if (n >= 10)
	{
		ft_print_decnbr(n / 10, ptr);
		ft_print_decnbr(n % 10, ptr);
	}
	else
		ft_print_char(n + '0', ptr);
}

void	ft_print_dec(int nb, int *ptr)
{
	size_t	n;

	if (nb == 0)
	{
		ft_print_char('0', ptr);
		return ;
	}
	if (nb < 0)
	{
		ft_print_char('-', ptr);
		n = nb;
		n = n * (-1);
	}
	else
		n = nb;
	ft_print_decnbr(n, ptr);
}
