/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:00:47 by mel-jira          #+#    #+#             */
/*   Updated: 2023/11/14 16:06:01 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		print_char(char c);
int		print_str(char *str);
int		print_address(void *address);
int		print_decimal(int nbr);
int		print_u_decimal(unsigned int nbr);
int		print_lower_hex(unsigned int nbr);
int		print_upper_hex(unsigned int nbr);
int		print_p_sign(void);

#endif