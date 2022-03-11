/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:44:17 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/09 16:08:32 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr2(const char *s, int c)
{
	size_t			i;
	size_t			l;

	i = 0;
	l = ft_strlen(s);
	while (i <= l)
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (0);
}
