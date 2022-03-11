/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:22:22 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/08 19:05:24 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(t_data *flow)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (flow->map[i])
	{
		j = 0;
		while (flow->map[i][j])
		{
			printf("%c", flow->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
