/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:07:15 by cbourre           #+#    #+#             */
/*   Updated: 2022/04/25 15:48:40 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *s, int *ptr)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_print_str("(null)", ptr);
		return ;
	}
	while (s[i] != '\0')
	{
		ft_print_char(s[i], ptr);
		i++;
	}
}
