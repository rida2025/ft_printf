/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:01:44 by mel-jira          #+#    #+#             */
/*   Updated: 2023/11/14 14:39:53 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hexaddress(unsigned long address)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (address > 15)
		print_hexaddress(address / 16);
	print_char(hex[address % 16]);
}

static	int	hexlen(unsigned long nbr)
{
	int	count;

	count = 1;
	while (nbr > 15)
	{
		count++;
		nbr = nbr / 16;
	}
	return (count);
}

int	print_address(void *address)
{
	unsigned long	address_value;
	int				count;

	address_value = (unsigned long)address;
	count = 0;
	print_str("0x");
	print_hexaddress(address_value);
	count = hexlen(address_value) + 2;
	return (count);
}
