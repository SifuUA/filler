# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okres <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 20:50:57 by okres             #+#    #+#              #
#    Updated: 2017/03/15 20:50:59 by okres            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a

C_NAME = bonus
P_NAME = filler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

C_SRC =	bonus_f/bonus.c

P_SRC = filler_f/fill_struct.c\
		filler_f/find.c\
		filler_f/find_bla_bla.c\
		filler_f/help.c\
		filler_f/lit_lit.c\
		filler_f/main.c\
		filler_f/other.c\
		filler_f/res.c\
		filler_f/resources.c

C_OBJ = $(C_SRC:.c=.o)
P_OBJ = $(P_SRC:.c=.o)

all:	$(LIB) $(C_NAME) $(P_NAME)

$(LIB):
		make -C ./libft

$(C_NAME): $(C_OBJ) 
		@$(CC) $(CFLAGS) $(C_OBJ) -o $(C_NAME) $(LIB)
%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<

$(P_NAME): $(P_OBJ) 
		@$(CC) $(CFLAGS) $(P_OBJ) -o $(P_NAME) $(LIB)
%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<

clean_bonus: 
		@rm -f $(C_OBJ)	
clean_filler: 
		@rm -f $(P_OBJ)
clean:
		@make clean -C ./libft
		@make clean_bonus
		@make clean_filler

fclean:
		@make fclean -C ./libft
		@make clean
		@rm -f $(C_NAME)
		@rm -f $(P_NAME)
re:
		@make fclean
		@make all
