/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:26:48 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/01/08 20:06:57 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_opcje(const char *insert, void *arg)
{
	int	i;

	i = 0;
	if (*insert == 'c')
		i += print_char((int)arg);
	else if (*insert == 's')
		i += print_string((char *)arg);
	else if (*insert == 'p')
		i += print_pointer((unsigned long)arg, 87);
	else if (*insert == 'd')
		i += print_int((int)arg);
	else if (*insert == 'i')
		i += print_int((int)arg);
	else if (*insert == 'u')
		i += print_uint((unsigned int)arg);
	else if (*insert == 'x')
		i += print_hex((unsigned int)arg, 87);
	else if (*insert == 'X')
		i += print_hex((unsigned int)arg, 55);
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
		if (*insert == %)
		{
			insert++;
			if (ft_strchr("cspdiuxX%", *insert))
				i += type(insert, va_arg(args, void *));
			else if (*input == '%')
				i += print_char('%');
		}
		else
			i = i + print_char(*insert);
		insert++;
	}
	va_end(args);
	return (i);
}
