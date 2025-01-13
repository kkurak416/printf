/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:20:46 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/01/11 12:36:31 by kkurowsk         ###   ########.fr       */
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
	if (temp == 0)
	{
		*strlen = 1;
		str = calloc(2, sizeof(char));
		return (str);
	}
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*strlen = i;
	return (str);
}

static void	ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

static void	converttohex(unsigned int tempo, char *printout, int i, int asci)
{
	while (tempo != 0)
	{
		if ((tempo % 16) < 10)
			printout[i] = (tempo % 16) + 48;
		else
			printout[i] = (tempo % 16) + asci;
		tempo = tempo / 16;
		i++;
	}
}

int	print_hex(unsigned int value, int asci)
{
	unsigned int	tempo;
	char			*printout;
	int				i;
	int				*iptr;

	i = 0;
	iptr = &i;
	tempo = value;
	printout = cr_str(value, iptr);
	if (!printout)
		return (0);
	if (value == 0)
		printout[0] = '0';
	else
	{
		i = 0;
		converttohex(tempo, printout, i, asci);
		ft_strrev(printout);
	}
	ft_putstr_fd(printout, 1);
	i = ft_strlen(printout);
	free(printout);
	return (i);
}
