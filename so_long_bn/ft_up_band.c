/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_band.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:09:00 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/10 17:10:49 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_up_band(t_data *flow)
{
	char	*num;

	mlx_put_image_to_window(flow->mlx, flow->win,
		flow->img_black_sc, (3) * 32, 0);
	num = ft_itoa(flow->pl_moves);
	mlx_string_put(flow->mlx, flow->win, 3 * 32, 0, 0xFFB100, num);
	free(num);
}
