# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 16:04:22 by qmuntada          #+#    #+#              #
#    Updated: 2015/01/17 16:44:29 by qmuntada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFLAGS = -Wall -Werror -Wextra
SRC = fdf.c color.c command.c display.c draw.c draw_triangle.c env.c \
		 eventkey.c height.c isometric.c parallel.c
OBJ = $(SRC:.c=.o)
LIBX = -lm -I/usr/X11/include -L/usr/X11/lib -lX11 -lXext -lmlx libft/libft.a
LIBXL = -lm libft/libft.a -L/usr/lib/X11 -lmlx -lXext -lX11


all : $(NAME)

.PHONY : linux libft clean fclean re norme

$(NAME) : libft
	@echo "Creating MAC executable $(NAME) ..."
	@gcc $(CFLAGS) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIBX)

linux: libft
	@echo "Creating LINUX executable $(NAME) ..."
	@gcc $(CFLAGS) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIBXL)

libft:
	@make -C libft fclean
	@make -C libft

clean :
	@echo "Removing object files ..."
	@rm -f $(OBJ)

fclean : clean
	@echo "Removing $(NAME) ..."
	@rm -f $(NAME)

re : fclean all
