# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 16:04:22 by qmuntada          #+#    #+#              #
#    Updated: 2015/01/17 16:45:40 by qmuntada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra 
SOURCE = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		 ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		 ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		 ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		 ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		 ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
		 ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		 ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		 ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
		 ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		 ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
		 ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_swap.c \
		 ft_max.c ft_islower.c ft_isupper.c ft_sqrt.c ft_power.c \
		 ft_btw.c ft_isblank.c ft_lstpushback.c ft_lstlen.c ft_strcf.c \
		 ft_lstclear.c ft_lstnclear.c get_next_line.c \

OBJ = $(SOURCE:.c=.o)

.PHONY : all clean fclean re norme

all : $(NAME)

$(NAME) :  $(OBJ)
	@echo "Creating archive $@ ..."
	@export result=`ar rcs $@ $(OBJ) 2>&1` ; \

clean :
	@echo "Removing object files ..."
	@rm -rf $(OBJ)

fclean : clean
	@echo "Removing $(NAME) ..."
	@rm -rf $(NAME)

re : fclean all

norme : 
	norminette $(SOURCE)
