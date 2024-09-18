/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-17 14:02:55 by aberenge          #+#    #+#             */
/*   Updated: 2024-09-17 14:02:55 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(const char *str, int fd);
int		ft_putnbr_fd(int nb, int fd);
int		ft_print_hex_fd_maj(int nb, int fd);
int		ft_print_hex_fd_min(int nb, int fd);

void	ft_parser(char c, int *counter, va_list *args);

#endif
