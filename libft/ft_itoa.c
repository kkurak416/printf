/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <kkurowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:49:13 by kkurowsk          #+#    #+#             */
/*   Updated: 2024/12/18 17:41:47 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static size_t	count(int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int	absolut(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*loc;
	size_t	check;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		i = 1;
	check = count(n) + i;
	loc = malloc(check + 1);
	if (!loc)
		return (NULL);
	loc[check] = '\0';
	if (i)
		loc[0] = '-';
	while (n != 0)
	{
		loc[check - 1] = absolut(n % 10) + 48;
		n /= 10;
		check--;
	}
	return (loc);
}
