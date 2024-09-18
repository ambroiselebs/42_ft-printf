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
	if (c == 's')
		*counter += ft_putstr_fd(va_arg(*args, char *), 1);
	if (c == 'i' || c == 'd')
		*counter += ft_putnbr_fd(va_arg(*args, int), 1);
	if (c == 'u')
		*counter += ft_putnbr_fd(va_arg(*args, unsigned int), 1);
	if (c == 'x')
		*counter += ft_print_hex_fd_min(va_arg(*args, int), 1);
	if (c == 'X')
		*counter += ft_print_hex_fd_maj(va_arg(*args, int), 1);
	if (c == '%')
		*counter += ft_putchar_fd('%', 1);
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
/*
int	main(void)
{
	ft_printf("je suis %s, J'ai %i ans\n\n", "Ambroise", 18);
	ft_printf("-> Compte %d\n", ft_printf("Hello world\n"));

	ft_printf("\n\nNombre 16 : %x", -42);
	printf("\nNombre 16 : %x\n", -42);
	return (0);
}*/
