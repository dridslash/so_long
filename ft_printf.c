/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:29:03 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/11 18:10:57 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static int	ft_casecheck(const char *str, va_list p, int i, int j)
{
	while (str[i])
	{
		if (str[i] != '%')
			j += ft_putchar(str[i]);
		else if (str[++i] == 's')
			j += ft_putstr((char *)va_arg(p, char *));
		else if (str[i] == 'c')
			j += ft_putchar((char)va_arg(p, int));
		else if (str[i] == 'd' || str[i] == 'i')
			j += ft_putnbr(va_arg(p, int));
		else if (str[i] == 'X')
			j += ft_puthexmaj((unsigned int)va_arg(p, unsigned int));
		else if (str[i] == 'x')
			j += ft_puthex((unsigned int)va_arg(p, unsigned int));
		else if (str[i] == 'p')
			j += ft_linkhex(va_arg(p, unsigned long long));
		else if (str[i] == 'u')
			j += ft_putu((unsigned int)va_arg(p, unsigned int));
		else if (str[i] == '%')
			j += ft_putchar('%');
		i++;
	}
	return (j);
}

int	ft_printf(const char *pr, ...)
{
	va_list	arg_ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(arg_ptr, pr);
	i = ft_casecheck(pr, arg_ptr, i, j);
	va_end(arg_ptr);
	return (i);
}
