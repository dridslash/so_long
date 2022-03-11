/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:33:04 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/11 12:06:08 by mnaqqad          ###   ########.fr       */
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
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned int n)
{
	if (n > 15)
		ft_puthex(n / 16);
	if ((n % 16) > 9)
		put((n % 16) + 87);
	else if ((n % 16) <= 9)
		put((n % 16) + '0');
	return (ft_counter(n));
}
/*int main(void)
{
    ft_puthex(123,0);
}*/