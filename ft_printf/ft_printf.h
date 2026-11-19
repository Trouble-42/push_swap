/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:56:56 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/14 16:57:16 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_address(void *adress);
int	ft_putchar(char c);
int	ft_putnbr_c(int nb);
int	ft_putnbrhexacaps(unsigned int nb);
int	ft_putnbrhexamin(unsigned int nb);
int	ft_putstr_c(char *s);
int	ft_putunsignednbr(unsigned int nb);
int	ft_printf(const char *str, ...);

#endif
