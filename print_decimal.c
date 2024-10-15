/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:02:01 by mel-jira          #+#    #+#             */
/*   Updated: 2023/11/14 14:29:49 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbrlen(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		count = 2;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		nbr = nbr * -1;
		print_char('-');
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	print_char(nbr % 10 + 48);
}

int	print_decimal(int nbr)
{
	int	count;

	count = nbrlen(nbr);
	ft_putnbr(nbr);
	return (count);
}
