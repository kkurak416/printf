/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:29:48 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/01/11 12:31:33 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *insert, ...);
int		print_pointer(unsigned long value, int asci);
int		print_uint(unsigned int nb);
int		print_char(char c);
int		print_int(int n);
int		print_hex(unsigned int value, int asci);
int		print_string(char *s);
#endif
