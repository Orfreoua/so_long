/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:24:23 by orfreoua          #+#    #+#             */
/*   Updated: 2021/10/24 15:16:42 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	len(unsigned long long nb)
{
	int		len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(unsigned long long nb)
{
	char				*str;
	unsigned long long	n;
	unsigned long long	i;

	if (nb <= 0)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	n = nb;
	i = len(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i--] = '\0';
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}
