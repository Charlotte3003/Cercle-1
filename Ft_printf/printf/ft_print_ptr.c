/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:25:44 by cbourre           #+#    #+#             */
/*   Updated: 2022/04/26 15:43:02 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_p(unsigned long n, int *ptr)
{
	if (n >= 16)
	{
		ft_print_p(n / 16, ptr);
		ft_print_p(n % 16, ptr);
	}
	else if (n >= 10)
		ft_print_char((n + 'a' - 10), ptr);
	else if (n < 10)
		ft_print_char(n + '0', ptr);
}

void	ft_print_ptr(unsigned long p, int *ptr)
{
	unsigned long	n;

	if (!p)
	{
		ft_print_str("(nil)", ptr);
		return ;
	}
	ft_print_str("0x", ptr);
	n = p;
	ft_print_p(n, ptr);
}
