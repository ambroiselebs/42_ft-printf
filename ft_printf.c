/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-17 14:03:23 by aberenge          #+#    #+#             */
/*   Updated: 2024-09-17 14:03:23 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parser(char c, int *counter, va_list *args)
{
	if (c == 'c')
		*counter += ft_putchar_fd(va_arg(*args, int), 1);
	else if (c == 's')
		*counter += ft_putstr_fd(va_arg(*args, char *), 1);
	else if (c == 'i' || c == 'd')
		*counter += ft_putnbr_fd(va_arg(*args, int), 1);
}

int	ft_printf(const char *str, ...)
{
	int		counter;
	va_list	args;

	counter = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			ft_parser(*++str, &counter, &args);
		else
			counter += ft_putchar_fd(str[0], 1);
		str++;
	}
	va_end(args);
	return (counter);
}

int	main(void)
{
	ft_printf("je suis %s\nJ'ai %i ans\n", "Ambroise", 18);
	return (0);
}
