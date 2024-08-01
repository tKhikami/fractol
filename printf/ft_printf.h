/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:39:58 by nyrandri          #+#    #+#             */
/*   Updated: 2024/05/02 12:38:38 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif

int	ft_putchar_fd(char c, int fd);
int	ft_putstr(char *str);
int	ft_strlen(const char *str);
int	ft_print_base(const char *str, unsigned long long number);
int	ft_print_array(unsigned long number);
int	ft_print_integer(int number);
int	ft_printf(const char *str, ...);
int	ft_print_positif_integer(unsigned int number);
int	ft_print_hexa(unsigned int number, int c);

#endif
