/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:42 by akabbaj           #+#    #+#             */
/*   Updated: 2025/02/11 16:01:42 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	in_str(char	*str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		if (c == str[i++])
			return (1);
	return (0);
}

void	*ft_calloc(unsigned int nmemb, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!nmemb || !size)
		return (malloc(1));
	result = malloc(size * nmemb);
	if (!result)
		return (0);
	while (i < (size * nmemb))
		result[i++] = 0;
	return (result);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*concat(char *s1, char *s2)
{
	int		l1;
	int		l2;
	char	*result;
	int		i;
	int		j;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!result)
		return (free_return(s1));
	i = -1;
	j = -1;
	while (s1[++i])
		result[i] = s1[i];
	while (s2[++j])
		result[i++] = s2[j];
	result[i] = 0;
	free(s1);
	return (result);
}

void	*free_return(void *tofree)
{
	free(tofree);
	return (0);
}
