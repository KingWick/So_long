/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:59 by akram             #+#    #+#             */
/*   Updated: 2023/02/21 19:49:06 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_base_ptr(unsigned long long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_putnbr_base_ptr(nbr / 16, base);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}

int	ft_putnbr_base_xx(unsigned int nbr, char c)
{
	int		count;
	char	*base;
	char	*base_maj;

	base = "0123456789abcdef";
	base_maj = "0123456789ABCDEF";
	count = 0;
	if (c == 'x')
	{
		if (nbr >= 16)
			count += ft_putnbr_base_xx(nbr / 16, c);
		count += ft_putchar(base[nbr % 16]);
		return (count);
	}
	else
	{
		if (nbr >= 16)
			count += ft_putnbr_base_xx(nbr / 16, c);
		count += ft_putchar(base_maj[nbr % 16]);
		return (count);
	}
}

void	ft_exec_flags(const char *str, int i, int *count, va_list lst)
{
	unsigned long long	ptr;

	if (str[i] == 'c')
		*count += ft_putchar(va_arg(lst, int));
	if (str[i] == 'd')
		*count += ft_putnbr(va_arg(lst, int));
	if (str[i] == 's')
		*count += ft_putstr(va_arg(lst, char *));
	if (str[i] == 'p')
	{
		ptr = va_arg(lst, unsigned long long);
		if (!ptr)
			*count += write(1, "(nil)", 5);
		else
		{
			*count += write(1, "0x", 2);
			*count += ft_putnbr_base_ptr(ptr, "0123456789abcdef");
		}
	}
	if (str[i] == 'u')
		*count += ft_putnbr_u(va_arg(lst, unsigned int));
	if (str[i] == 'i')
		*count += ft_putnbr(va_arg(lst, int));
	if (str[i] == 'x' || str[i] == 'X')
		*count += ft_putnbr_base_xx(va_arg(lst, unsigned int), str[i]);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	lst;

	va_start (lst, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
			count += ft_putchar('%');
			ft_exec_flags(str, i, &count, lst);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end (lst);
	return (count);
}
