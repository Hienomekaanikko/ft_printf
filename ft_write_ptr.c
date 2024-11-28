/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:44:03 by msuokas           #+#    #+#             */
/*   Updated: 2024/11/28 16:03:55 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	ft_put_ptr(uintptr_t n)
{
	int result;

	result = 0;
	if (n >= 16)
	{
		result = ft_put_ptr(n / 16);
		if (result == -1)
			return (-1);
		result = ft_put_ptr(n % 16);
		if (result == -1)
			return (-1);
	}
	else
	{
		if (n <= 9)
			result = ft_write_char(n + '0');
		else
			result = ft_write_char(n - 10 + 'a');
		if (result == -1)
			return (-1);
	}
	return (0);
}

int	ft_write_ptr(uintptr_t ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		if (ft_write_string("(nil)") == -1)
			return (-1);
		return (5);
	}
	else
	{
		if (ft_write_string("0x") == -1)
			return (-1);
		len += 2;
		ft_put_ptr(ptr);
		if (ft_ptr_len(ptr) == -1)
			return (-1);
		len += ft_ptr_len(ptr);
	}
	return (len);
}
