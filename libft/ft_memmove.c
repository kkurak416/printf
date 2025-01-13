/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:09:45 by kkurowsk          #+#    #+#             */
/*   Updated: 2024/12/03 14:52:45 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	nums(unsigned char *dest, const unsigned char *src, size_t num)
{
	while (num > 0)
	{
		dest[num - 1] = src[num - 1];
		num--;
	}
}

void	*ft_memmove( void *destination, const void *source, size_t num )
{
	unsigned char		*dest;
	const unsigned char	*src;
	size_t				i;

	if (!destination && !source)
		return (NULL);
	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (dest > src)
		nums(dest, src, num);
	else
	{
		i = 0;
		while (i < num)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (destination);
}
