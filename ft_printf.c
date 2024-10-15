/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:20:36 by mel-jira          #+#    #+#             */
/*   Updated: 2023/11/14 12:59:47 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char format, va_list argp)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(argp, int));
	else if (format == 's')
		count += print_str(va_arg(argp, char *));
	else if (format == 'p')
		count += print_address(va_arg(argp, void *));
	else if (format == 'd' || format == 'i')
		count += print_decimal(va_arg(argp, int));
	else if (format == 'u')
		count += print_u_decimal(va_arg(argp, unsigned int));
	else if (format == 'x')
		count += print_lower_hex(va_arg(argp, unsigned int));
	else if (format == 'X')
		count += print_upper_hex(va_arg(argp, unsigned int));
	else if (format == '%')
		count += print_p_sign();
	else
		count += print_char(format);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	argp;

	va_start(argp, format);
	count = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), argp);
		else
			count += print_char(*format);
		format++;
	}
	va_end(argp);
	return (count);
}
