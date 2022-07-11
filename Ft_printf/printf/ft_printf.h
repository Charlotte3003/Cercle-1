/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:14:26 by cbourre           #+#    #+#             */
/*   Updated: 2022/04/26 15:14:28 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_print_char(char c, int *ptr);
void	ft_print_str(char *s, int *ptr);
void	ft_print_ptr(unsigned long p, int *ptr);
void	ft_print_dec(int nb, int *ptr);
void	ft_print_dec_uns(unsigned int nb, int *ptr);
void	ft_print_hexa(unsigned int nb, char l, int *ptr);

#endif
