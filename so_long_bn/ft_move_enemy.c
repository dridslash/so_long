/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:44:26 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/11 18:25:46 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_animate_enemy_forward(t_data *flow)
{
	int	x;
	int	y;
	int	place;

	x = 0;
	y = 0;
	place = 0;
	ft_loop_one(flow, x, y, place);
}

void	ft_animate_enemy_backward(t_data *flow)
{
	int	x;
	int	y;
	int	place;

	x = 0;
	y = 0;
	place = 0;
	ft_loop_two(flow, x, y, place);
}

void	ft_animate_enemy(t_data *flow)
{
	flow->frame_enemy++;
	if (flow->frame_enemy == 9000)
	{
		ft_animate_enemy_forward(flow);
	}
	if (flow->frame_enemy == 40000)
	{
		ft_animate_enemy_backward(flow);
		flow->frame_enemy = 0;
	}
}
