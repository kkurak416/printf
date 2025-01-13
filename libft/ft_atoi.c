/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:05:57 by kkurowsk          #+#    #+#             */
/*   Updated: 2024/12/10 15:59:36 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (!*nptr)
		return (0);
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			i = -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		j = j * 10 + *nptr - 48;
		nptr++;
	}
	return (j * i);
}
