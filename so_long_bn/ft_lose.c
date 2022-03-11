/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:11:50 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/12 14:17:50 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_lose(t_data *flow)
{
	ft_printf("\033[1;31myou Lose you touched enemy patrol!!");
	usleep(50000);
	mlx_destroy_window(flow->mlx, flow->win);
	exit(1);
}
