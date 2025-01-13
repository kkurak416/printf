/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:41:02 by kkurowsk          #+#    #+#             */
/*   Updated: 2024/12/16 17:00:53 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		fin;
	char	*wyn;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	fin = (ft_strlen(s1) - 1);
	while (fin > start && ft_strchr(set, s1[fin]))
		fin--;
	if (fin < start)
		return (ft_strdup(""));
	wyn = (char *)malloc (fin - start + 2);
	if (!wyn)
		return (NULL);
	ft_strlcpy (wyn, s1 + start, fin - start + 2);
	return (wyn);
}
