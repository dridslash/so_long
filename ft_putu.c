/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:41:54 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/11 12:06:25 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put(char c)
{
	write(1, &c, 1);
}

static int	ft_counter(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putu(unsigned int n)
{
	if (n > 9)
	{
		ft_putu(n / 10);
	}
	put(n % 10 + '0');
	return (ft_counter(n));
}
