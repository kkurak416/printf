/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 07:31:16 by kkurowsk          #+#    #+#             */
/*   Updated: 2024/12/08 07:39:29 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	i = ft_strlen(little);
	if (i == 0 || (!big && len == 0))
		return ((char *)big);
	while (big[j] != '\0' && j < len)
	{
		k = 0;
		while (big[j + k] == little[k] && little[k] != '\0' && (j + k) < len)
		{
			k++;
		}
		if (little[k] == '\0')
		{
			big += j;
			return ((char *)big);
		}
		j++;
	}
	return (NULL);
}
