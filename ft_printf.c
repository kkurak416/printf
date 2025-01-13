/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:26:48 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/01/08 21:35:55 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_opcje(const char *insert, va_list args)
{
	int	i;

	i = 0;
	if (*insert == 'c')
		i += print_char(va_arg(args, int));
	else if (*insert == 's')
		i += print_string(va_arg(args, char *));
	else if (*insert == 'p')
		i += print_pointer(va_arg(args, unsigned long), 87);
	else if (*insert == 'd')
		i += print_int(va_arg(args, int));
	else if (*insert == 'i')
		i += print_int(va_arg(args, int));
	else if (*insert == 'u')
		i += print_uint(va_arg(args, unsigned int));
	else if (*insert == 'x')
		i += print_hex(va_arg(args, unsigned int), 87);
	else if (*insert == 'X')
		i += print_hex(va_arg(args, unsigned int), 55);
	return (i);
}

int	ft_printf(const char *insert, ...)
{
	va_list			args;
	unsigned int	i;

	i = 0;
	va_start(args, insert);
	while (*insert != '\0')
	{
		if (*insert == '%')
		{
			insert++;
			if (ft_strchr("cspdiuxX", *insert))
				i += ft_opcje(insert, args);
			else if (*insert == '%')
				i += print_char('%');
		}
		else
			i = i + print_char(*insert);
		insert++;
	}
	va_end(args);
	return (i);
}
