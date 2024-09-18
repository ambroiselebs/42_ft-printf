/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-18 09:35:37 by aberenge          #+#    #+#             */
/*   Updated: 2024-09-18 09:35:37 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hex_fd_maj(int nb, int fd)
{
	char			*hex_digits;
	char			hex_res[9];
	int				i;
	int				counter;
	unsigned int	unsigned_nb;

	hex_digits = "0123456789ABCDEF";
	i = 0;
	counter = 0;
	if (nb == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	unsigned_nb = (unsigned int) nb;
	while (unsigned_nb > 0)
	{
		counter++;
		hex_res[i++] = hex_digits[unsigned_nb % 16];
		unsigned_nb = unsigned_nb / 16;
	}
	i--;
	while (i >= 0)
		write(fd, &hex_res[i--], 1);
	return (counter);
}

int	ft_print_hex_fd_min(int nb, int fd)
{
	char			*hex_digits;
	char			hex_res[9];
	int				i;
	int				counter;
	unsigned int	unsigned_nb;

	hex_digits = "0123456789abcdef";
	i = 0;
	counter = 0;
	if (nb == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	unsigned_nb = (unsigned int) nb;
	while (unsigned_nb > 0)
	{
		counter++;
		hex_res[i++] = hex_digits[unsigned_nb % 16];
		unsigned_nb = unsigned_nb / 16;
	}
	i--;
	while (i >= 0)
		write(fd, &hex_res[i--], 1);
	return (counter);
}
