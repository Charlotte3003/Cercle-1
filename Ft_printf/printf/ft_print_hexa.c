/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:36:52 by cbourre           #+#    #+#             */
/*   Updated: 2022/04/26 14:32:07 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hexanbr(unsigned int n, char l, int *ptr)
{
	if (n >= 16)
	{
		ft_print_hexanbr(n / 16, l, ptr);
		ft_print_hexanbr(n % 16, l, ptr);
	}
	else if (n >= 10)
	{
		if (l == 'x')
			ft_print_char((n + 'a' - 10), ptr);
		if (l == 'X')
			ft_print_char((n + 'A' - 10), ptr);
	}
	else if (n < 10)
		ft_print_char(n + '0', ptr);
}

void	ft_print_hexa(unsigned int nb, char l, int *ptr)
{
	unsigned int	n;

	if (nb == 0)
	{
		ft_print_char('0', ptr);
		return ;
	}
	if (nb > 0)
		n = nb;
	ft_print_hexanbr(n, l, ptr);
}
