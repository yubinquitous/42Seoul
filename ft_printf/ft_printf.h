/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:06:19 by yubchoi           #+#    #+#             */
/*   Updated: 2022/01/01 13:40:25 by yubinquit        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

# define ERR -1

int	ft_printf(const char *arg, ...);
int	parse_arg(va_list ap, char *arg);
int	check_format(va_list ap, char type, int *nprintf);
int	nbr_len(char type, unsigned long nbr);
int	print_nbr(char type, unsigned long nbr);
int	print_str(char *str);
int	print_char(char c);

#endif
