# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 21:17:31 by lvichi            #+#    #+#              #
#    Updated: 2023/12/18 20:09:24 by lvichi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
MINILIBX = -L minilibx-linux -lmlx -lXext -lX11
LIBFT = -L libft -lft
FILES = src/*.c
OBJS = obj/*.o
BONUS_FILES = bonus_src/*_bonus.c
BONUS_OBJS = bonus_obj/*_bonus.o
RM = rm -fr

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(MINILIBX) $(LIBFT) -o $(BONUS_NAME)

$(OBJS): $(FILES)
	@make -C minilibx-linux -s
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $(FILES)
	@mv *.o obj/

$(BONUS_OBJS): $(BONUS_FILES)
	@make -C minilibx-linux -s
	@make -C libft -s
	@mkdir -p bonus_obj
	@$(CC) $(CFLAGS) -c $(BONUS_FILES)
	@mv *_bonus.o bonus_obj/

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS) obj bonus_obj
	@make clean -C minilibx-linux -s
	@make clean -C libft -s

fclean:
	@$(RM) $(OBJS) $(BONUS_OBJS) $(NAME) $(BONUS_NAME) obj bonus_obj
	@make clean -C minilibx-linux -s
	@make fclean -C libft -s

re: fclean all

bonus_re : fclean bonus
