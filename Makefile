# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 21:17:31 by lvichi            #+#    #+#              #
#    Updated: 2023/12/14 00:39:28 by lvichi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr
FILES = src/*.c
OBJS = obj/*.o
LIBFT = -L libft -lft
MINILIBX = -L minilibx-linux -lmlx -lXext -lX11
#BONUS_FILES = *_bonus.c
#BONUS_OBJS = *_bonus.o

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME)

$(OBJS): $(FILES)
	@clear
#	@python3 ~/.local/bin/norminette $(FILES)
	@make -C libft -s
	@make -C minilibx-linux -s
	@mkdir -p obj
	@$(CC) $(CFLAGS) -l lib -c $(FILES)
	@mv *.o obj/

#$(BONUS_OBJS): $(BONUS_FILES)
#	$(CC) $(CFLAGS) -c $(BONUS_FILES)

clean:
	@$(RM) $(OBJS)
	@rmdir obj
	@make clean -C minilibx-linux -s
	@make clean -C libft -s

fclean:
	@$(RM) $(OBJS) $(NAME)
	@rmdir obj
	@make clean -C minilibx-linux -s
	@$(RM) minilibx-linux/Makefile.gen
	@make fclean -C libft -s

re: fclean all

#bonus: $(BONUS_OBJS) $(OBJS)
#	$(AR) $(NAME) $(OBJS)