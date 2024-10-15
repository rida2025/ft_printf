/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_upper_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:02:59 by mel-jira          #+#    #+#             */
/*   Updated: 2023/11/14 14:40:21 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	hexlen(unsigned int nbr)
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

static	void	convert_tohex(unsigned int nbr)
{
	char	*lowerhex;

	lowerhex = "0123456789ABCDEF";
	if (nbr > 15)
		convert_tohex(nbr / 16);
	print_char(lowerhex[nbr % 16]);
}

int	print_upper_hex(unsigned int nbr)
{
	int	count;

	count = hexlen(nbr);
	convert_tohex(nbr);
	return (count);
}
