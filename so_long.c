/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:04:28 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/13 10:05:45 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void)
{
	exit(0);
}

void	ft_global_func(t_data *flow, char **argv)
{
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
		find_player(flow);
		flow->pl_moves = 0;
		mlx_hook(flow->win, 2, 1L << 0, ft_move, flow);
		mlx_hook(flow->win, 17, 1L >> 17, close_window, flow);
		mlx_loop(flow->mlx);
	}
}

int	main(int argc, char **argv)
{
	t_data	*flow;

	flow = malloc(sizeof(t_data));
	if (argc == 2)
	{
		ft_global_func(flow, argv);
	}
	else
	{
		perror("Error\n");
	}
}
