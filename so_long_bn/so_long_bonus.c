/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:04:28 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/12 17:47:44 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../so_long.h"
#include <stdlib.h>

int	close_window(void)
{
	exit(0);
}

void	ft_global_func(char **argv, t_data *flow)
{
	flow->frame = 0;
	flow->frame_coin = 0;
	flow->frame_enemy = 0;
	flow->map = ft_read_map(argv, flow);
	if (flow->map == NULL)
	{
		ft_printf("Error\ninvalid map somthing wrong with your map elements\n");
		exit(1);
	}
	else
	{
	flow->mlx = mlx_init();
		render_map(flow, argv);
	flow->pl_moves = 0;
		mlx_string_put(flow->mlx, flow->win, 0, 0, 0xFFB100, "moves :");
		mlx_hook(flow->win, 2, 1L << 0, ft_move, flow);
		mlx_hook(flow->win, 17, 1L >> 17, close_window, flow);
		mlx_loop_hook(flow->mlx, ft_animation, flow);
		mlx_loop(flow->mlx);
	}
}

int	main(int argc, char **argv)
{
	t_data	*flow;

	flow = malloc(sizeof(t_data));
	if (argc == 2)
	{
		ft_global_func(argv, flow);
	}
	else
		perror("Error\n");
}
