/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:21:22 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/11 12:15:29 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_win(t_data *flow)
{
	flow->pl_moves++;
	ft_printf("\033[1;32m you win!!");
	mlx_destroy_window(flow->mlx, flow->win);
	exit(1);
}
