/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:38:19 by akabbaj           #+#    #+#             */
/*   Updated: 2025/02/20 11:38:19 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	result;

	result = 0;
	neg = 1;
	i = 0;
	while (wspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		neg = -1;
	if (nptr[i] == '-' || (nptr[i] == '+' && nptr[i + 1] != '-'))
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += (nptr[i++] - '0');
	}
	return (result * neg);
}

int	get_val(char c, char *vals)
{
	int	count;

	count = 0;
	while (vals[count])
	{
		if (count > 9)
		{
			if (c == vals[count] || c == vals[count] + 32)
				return (count);
		}
		else
			if (c == vals[count])
				return (count);
		count++;
	}
	return (0);
}

int	ft_hexatoi(const char *nptr)
{
	int		i;
	int		result;

	result = 0;
	i = 2;
	while (nptr[i])
	{
		result *= 16;
		result += (get_val(nptr[i], "0123456789ABCDEF"));
		i++;
	}
	return (result);
}
