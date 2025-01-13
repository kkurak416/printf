/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:07:16 by kkurowsk          #+#    #+#             */
/*   Updated: 2024/12/16 14:07:50 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = malloc(len1 + len2 + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		ret[i] = s2[i - len1];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
