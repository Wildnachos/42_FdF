/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:08:25 by akabbaj           #+#    #+#             */
/*   Updated: 2025/02/20 11:08:25 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	wspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	in(char c, char *set)
{
	int	count;

	count = 0;
	while (set[count])
	{
		if (c == set[count])
			return (1);
		count++;
	}
	return (0);
}

int	word_count(char *s, char *set)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	while (s[count])
	{
		while (in(s[count], set))
			count++;
		if (!in(s[count], set) && s[count])
			count2++;
		while (!in(s[count], set) && s[count])
			count++;
	}
	return (count2);
}

char	**create_arr(char *s, char *set, int words)
{
	int		count;
	int		count2;
	int		count3;
	char	**res;

	count = -1;
	count2 = 0;
	res = malloc(sizeof(char *) * (words + 1));
	while (++count < words)
	{
		while (in(s[count2], set))
			count2++;
		count3 = 0;
		while (!in(s[count2 + count3], set) && s[count2 + count3])
			count3++;
		res[count] = malloc(sizeof(char) * (count3 + 1));
		if (!res[count])
			return (0);
		count3 = 0;
		while (!in(s[count2], set) && s[count2])
			res[count][count3++] = s[count2++];
		res[count][count3] = 0;
	}
	res[count] = 0;
	return (res);
}

char	**ft_split(char *s, char *set)
{
	int		words;
	char	**res;

	words = word_count(s, set);
	if (!words)
		return (0);
	res = create_arr(s, set, words);
	return (res);
}
