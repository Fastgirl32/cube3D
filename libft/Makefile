# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phnowak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 11:29:47 by phnowak           #+#    #+#              #
#    Updated: 2023/01/12 16:09:39 by phnowak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

SRC	= ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	\
	ft_printf/ft_check_format.c\
	ft_printf/ft_convert.c\
	ft_printf/ft_itoa_hex.c\
	ft_printf/ft_itoa_ten.c\
	ft_printf/ft_output_char.c\
	ft_printf/ft_output_decimal.c\
	ft_printf/ft_output_hex.c\
	ft_printf/ft_output_pointer.c\
	ft_printf/ft_output_string.c\
	ft_printf/ft_output_unsigned.c\
	ft_printf/ft_printf.c\
	ft_printf/ft_put_percent.c\
	ft_printf/ft_putchar.c\
	\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\

BONUS	=  ft_lstnew.c\
	   ft_lstadd_front.c\
	   ft_lstlast.c\
	   ft_lstsize.c\
	   ft_lstadd_back.c\
	   ft_lstdelone.c\
	   ft_lstclear.c\
	   ft_lstiter.c\
	   ft_lstmap.c\
	   ft_lstmap.c

OBJ	=	$(SRC:.c=.o)

OBJBONUS =	$(BONUS:.c=.o)

RM	=	rm -f

.PHONY: clean flcean all re

all:	$(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus:	$(OBJ) $(OBJBONUS)
	ar rcs $(NAME) $(OBJ) $(OBJBONUS)

clean:
	$(RM) $(OBJ) $(OBJBONUS)

fclean:
	$(RM) $(OBJ) $(OBJBONUS)
	$(RM) $(NAME)

re: fclean all
