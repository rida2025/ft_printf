# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 17:45:31 by mel-jira          #+#    #+#              #
#    Updated: 2023/11/14 14:51:44 by mel-jira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

COMPILER = cc

FLAGS = -Wall -Wextra -Werror

SRC_C = ft_printf.c \
		print_char.c \
		print_str.c \
		print_address.c \
		print_decimal.c \
		print_u_decimal.c \
		print_lower_hex.c \
		print_upper_hex.c \
		print_p_sign.c

OBJSRC = $(SRC_C:.c=.o)

.PHONY: $(NAME)

all: $(NAME)

$(NAME): $(OBJSRC) 
		ar -rc $(NAME) $(OBJSRC)

%.o: %.c ft_printf.h
	$(COMPILER) $(FLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJSRC)

fclean: clean
	rm -rf $(NAME)

re: fclean all
