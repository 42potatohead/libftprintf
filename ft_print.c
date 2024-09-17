/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabu-bak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:20:16 by zabu-bak          #+#    #+#             */
/*   Updated: 2024/09/11 19:29:18 by zabu-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(unsigned long ptr, int *len)
{
	if (!ptr)
	{
		ft_string("(nil)", len);
		return ;
	}
	write(1, "0x", 2);
	(*len) += 2;
	ft_hex(ptr, len, 'x');
}

void	ft_unsing(unsigned int num, int *len)
{
	if (num == 0)
	{
		ft_putstrlen('0');
		(*len)++;
		return ;
	}
	if (num > 9)
		ft_unsing(num / 10, len);
	(*len)++;
	ft_putstrlen(num % 10 + '0');
}

void	ft_putstrlen(char args)
{
	ft_putchar(args);
}

void	ft_string(char *args, int *len)
{
	int	i;

	if (!args)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	i = 0;
	while (args[i])
	{
		ft_putstrlen(args[i]);
		i++;
		(*len)++;
	}
}

void	ft_c(char args, int *len)
{
	ft_putchar(args);
	(*len)++;
}
