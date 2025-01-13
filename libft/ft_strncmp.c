/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:26:35 by kkurowsk          #+#    #+#             */
/*   Updated: 2024/12/08 00:00:20 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp( const char *s1, const char *s2, size_t n )
{
	size_t	i;

	i = 0;
	if ((!*s1 && !*s2) || n == 0)
		return (0);
	while (i < n)
	{
		if (!s1[i] || s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (s1[i - 1] - s2[i - 1]);
}
