/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:34:48 by kkurowsk          #+#    #+#             */
/*   Updated: 2024/12/18 15:18:04 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*effect;
	unsigned int	i;

	if (!s || !f)
		return (0);
	i = 0;
	effect = (char *)malloc(ft_strlen(s) + 1);
	if (!effect)
		return (NULL);
	while (s[i] != '\0')
	{
		effect[i] = f(i, s[i]);
		i++;
	}
	effect[i] = '\0';
	return (effect);
}
