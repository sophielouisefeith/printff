# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sfeith <sfeith@student.oodam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 20191028 14:14:30 by sfeith         #+#    #+#                 #
#    Updated: 2019/12/14 19:21:44 by sfeith        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft

SRC = ft_printf.c ft_analyze.c ft_plan.c ft_analyze_flags.c \
		ft_analyze_conversions.c ft_analyze_width.c \
		ft_reset.c ft_circuit_c.c ft_putchar.c ft_analyze_precision.c \
		ft_circuit_s.c ft_putstr.c ft_fill.c ft_count_int.c ft_circuit_i_d.c \
		ft_putstr.c ft_circuit_x.c ft_itoa_base.c ft_circuit_procent.c \
		ft_printf_copy.c ft_circuit_p.c ft_circuit_u.c \
		
OFILE = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILE)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rcs $(NAME) $(OFILE)

%.o: %.c
	gcc -g -I . -I libft/. -Wall -Werror -Wextra -c $< -o $@

clean:
	/bin/rm -f $(OFILE)
	@make clean -C $(LIBFT)

fclean: clean
	/bin/rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
