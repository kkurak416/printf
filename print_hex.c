/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:20:46 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/01/09 16:53:46 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"

static char	*cr_str(unsigned int value, int *strlen)
{
	unsigned int	temp;
	char			*str;
	int				i;

	i = 0;
	temp = value;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*strlen = i - 1;
	return (str);
}
/*
static int	print_nill(void)
{
	print_string("0x0");
	return(4);
}
*/
int	print_hex(unsigned int value, int asci)
{
	unsigned int	tempo;
	char			*printout;
	int				i;
	int				*iptr;

	iptr = &i;
	tempo = value;
	printout = cr_str(value, iptr);
	if (!printout)
		return (0);
//	if (value == 0)
//		return (print_nill());
	while (tempo != 0)
	{
		if ((tempo % 16) < 10)
			printout[i] = (tempo % 16) + 48;
		else
			printout[i] = (tempo % 16) + asci;
		tempo = tempo / 16;
	}
	ft_putstr_fd(printout, 1);
	i = ft_strlen(printout);
	free(printout);
	if (value == 0)
		i += print_char('0');
	return (i);
}
