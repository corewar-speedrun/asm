# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/06 13:09:37 by dmaznyts          #+#    #+#              #
#    Updated: 2017/11/19 12:38:33 by dmaznyts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

FLAGS = -Wall -Wextra -Werror

CC = gcc

LIB = libft/ft_atoi.o libft/ft_bzero.o libft/ft_isalnum.o libft/ft_isalpha.o\
	  libft/ft_isascii.o libft/ft_isdigit.o libft/ft_isprint.o libft/ft_itoa.o\
	  libft/ft_lstadd.o libft/ft_lstdel.o libft/ft_lstdelone.o libft/ft_lstiter.o\
	  libft/ft_lstmap.o libft/ft_lstnew.o libft/ft_memalloc.o libft/ft_memccpy.o\
	  libft/ft_memchr.o libft/ft_memcmp.o libft/ft_memcpy.o libft/ft_memdel.o\
	  libft/ft_memmove.o libft/ft_memset.o libft/ft_putchar.o libft/ft_putchar_fd.o\
	  libft/ft_putendl.o libft/ft_putendl_fd.o libft/ft_putnbr.o libft/ft_putnbr_fd.o\
	  libft/ft_putstr.o libft/ft_putstr_fd.o libft/ft_strcat.o libft/ft_strchr.o\
	  libft/ft_strclr.o libft/ft_strcmp.o libft/ft_strcpy.o libft/ft_strdel.o\
	  libft/ft_strdup.o libft/ft_strequ.o libft/ft_striter.o libft/ft_striteri.o\
	  libft/ft_strjoin.o libft/ft_strlcat.o libft/ft_strlen.o libft/ft_strmap.o\
	  libft/ft_strmapi.o libft/ft_strncat.o libft/ft_strncmp.o libft/ft_strncpy.o\
	  libft/ft_strnequ.o libft/ft_strnew.o libft/ft_strnstr.o libft/ft_strrchr.o\
	  libft/ft_strsplit.o libft/ft_strstr.o libft/ft_strsub.o libft/ft_strtrim.o\
	  libft/ft_tolower.o libft/ft_toupper.o libft/get_next_line.o\
	  libft/ft_itoa_base.o

OBJ = main.o validator1.o func.o func2.o list.o arg_parse1.o printer.o evalop.o\
	  printer2.o printer3.o arg_parse2.o arg_parse3.o arg_parse4.o byop.o list2.o\
	  validator2.o validator3.o arger1.o arger2.o byop2.o concat.o func3.o func4.o\
	  func5.o printer4.o func6.o

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ) $(LIB)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB) $(OBJ)
	@echo "\033[32;1m<asm>		| done\033[0m"

clean:
	@make -C libft clean
	@echo "\033[32;1m<libft *.o>	| removed\033[0m"
	@/bin/rm -f $(OBJ)
	@echo "\033[32;1m<asm *.o>	| removed\033[0m"
	
fclean: clean
	@make -C libft fclean
	@echo "\033[32;1m<libft.a>	| removed\033[0m"
	@/bin/rm -f $(NAME)
	@echo "\033[32;1m<./asm>		| removed\033[0m\n-------------------------"

$(LIB):
	@make -C libft
	@echo "\033[32;1m<libft>		| done\033[0m"

re: fclean all
