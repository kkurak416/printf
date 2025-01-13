/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:37:23 by kkurowsk          #+#    #+#             */
/*   Updated: 2024/12/16 10:52:40 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*copy;

	i = ft_strlen(s);
	copy = malloc(i + 1);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, s, i + 1);
	return (copy);
}
