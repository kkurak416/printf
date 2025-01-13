/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:10:48 by kkurowsk          #+#    #+#             */
/*   Updated: 2024/12/05 12:35:39 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;

	lsrc = ft_strlen((char *)src);
	if (size == 0)
		return (lsrc);
	ldst = ft_strlen((char *)dst);
	if (size <= ldst)
		return (lsrc + size);
	if (ldst < size - 1)
	{
		i = 0;
		while (ldst + i < size - 1 && src[i] != '\0')
		{
			dst[ldst + i] = src[i];
			i++;
		}
		dst[ldst + i] = '\0';
	}
	return (ldst + lsrc);
}
