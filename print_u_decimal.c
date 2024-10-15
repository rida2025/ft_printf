/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:02:40 by mel-jira          #+#    #+#             */
/*   Updated: 2023/11/14 14:36:25 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	nbrlen(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static	void	ft_putnbr(unsigned int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	print_char(nbr % 10 + 48);
}

int	print_u_decimal(unsigned int nbr)
{
	int	count;

	count = nbrlen(nbr);
	ft_putnbr(nbr);
	return (count);
}
