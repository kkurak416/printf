/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:01:15 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/01/08 19:32:30 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static char	*create_str(unsigned long value, int *strlen)
{
	int				i;
	unsigned long	temp;
	char			*str;

	i = 0;
	temp = value;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*strlen = i - 1;
	return (srt);
}

int	print_pointer(unsigned long value, int asci)
{
	unsigned long	tempo;
	char			*printout;
	int				i;
	int				iptr;

	iptr = &i;
	tempo = value;
	printout = create_str(value, iptr);
	if (!printout)
		return (0);
	while (tempo != 0 && i-- >= 0)
	{
		if ((tempo % 16) < 10)
			printout[i + 1] = (tempo % 16) + 48;
		else
			printout[i + 1] = (tempo % 16) + asci;
		tempo = tempo / 16;
	}
	i = ft_strlen(printout);
	i = i + print_string("0x")
		ft_putstr_fd(printout, 1);
	free (printout);
	if (value == 0)
		i += print_char('0');
	return (i);
}
