/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:11:16 by cbourre           #+#    #+#             */
/*   Updated: 2022/04/25 20:36:31 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_letter(char l, va_list params, int *ptr)
{
	if (l == 'c')
		ft_print_char(va_arg(params, int), ptr);
	if (l == 's')
		ft_print_str(va_arg(params, char *), ptr);
	if (l == 'p')
		ft_print_ptr(va_arg(params, unsigned long), ptr);
	if (l == 'd' || l == 'i')
		ft_print_dec(va_arg(params, int), ptr);
	if (l == 'u')
		ft_print_dec_uns(va_arg(params, unsigned int), ptr);
	if (l == 'x' || l == 'X')
		ft_print_hexa(va_arg(params, unsigned int), l, ptr);
	if (l == '%')
		ft_print_char('%', ptr);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	params;

	i = 0;
	va_start(params, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_letter(*str, params, &i);
		}
		else
			ft_print_char(*str, &i);
		str++;
	}
	va_end(params);
	return (i);
}
