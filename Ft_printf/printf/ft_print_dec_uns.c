/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_uns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:01:10 by cbourre           #+#    #+#             */
/*   Updated: 2022/04/25 19:17:43 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_dec_uns(unsigned int nb, int *ptr)
{
	if (nb == 0)
	{
		ft_print_char('0', ptr);
		return ;
	}
	if (nb > 0)
	{
		if (nb >= 10)
		{
			ft_print_dec_uns(nb / 10, ptr);
			ft_print_dec_uns(nb % 10, ptr);
		}
		else
			ft_print_char(nb + '0', ptr);
	}
	return ;
}
