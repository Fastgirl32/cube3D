# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: secker <secker@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 20:59:42 by phnowak           #+#    #+#              #
#    Updated: 2023/12/03 21:02:54 by secker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                    VARIABLES                                 #
################################################################################

NAME		=	cub3D

DISTRO		=	$(shell lsb_release -is)

CC		=	cc

ifeq ($(DISTRO),Arch)
	CC	=	clang
endif
ifeq ($(DISTRO),Debian)
	CC	=	clang
endif
ifeq ($(DISTRO),Ubuntu)
	CC	=	cc
endif

MAKEFLAGS	= -j$(nproc)

CFLAGS		=	-g -Wall -Wextra -Werror

RM	=	rm -f

RMR	=	rm -rf

RESET = "\033[0m"

COLOR = "\033[95m"

OBJ		=	$(SRC:.c=.o)

PATH_LIBFT	=	./libft

LIBFT		=	$(PATH_LIBFT)/libft.a

EXT_LIBS	=	-lmlx -lXext -lX11 -lm

DEPENDS		=	$(SRC:.c=.d)

DEBUGINFO	=	compile_commands.json .cache

.c.o:
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

################################################################################
#                                     SOURCES                                  #
################################################################################

SRC			=	src/check_access.c\
				src/check_color.c\
				src/check_map.c\
				src/cut_map.c\
				src/error_handling.c\
				src/event_handler.c\
				src/form_walls.c\
				src/game_start.c\
				src/get_rgb.c\
				src/ground_and_sky.c\
				src/init_player.c\
				src/init_raycast.c\
				src/input_check.c\
				src/main.c\
				src/movement.c\
				src/open_everything.c\
				src/process_cub.c\
				src/raycasting.c\
				src/set_player_spawn.c\
				src/split_info.c\
				src/read_inputfile.c\
				src/process_cub_utils.c

################################################################################
#                                      RULES                                   #
################################################################################

all:	compile	$(NAME)

$(LIBFT):
	printf $(COLOR)"Building libft..."$(RESET)"\n"
	make -s -C $(PATH_LIBFT)
	wait
	printf $(COLOR)"libft complete!"$(RESET)"\n"

$(NAME): $(OBJ) $(LIBFT)
	printf $(COLOR)"Building $(NAME)..."$(RESET)"\n"
	wait
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(EXT_LIBS)
	wait
	printf "\033[32m$(NAME) complete!\033[0m\n"

compile:
	if [ ! -n "$(wildcard $(OBJ))" ]; then \
	printf $(COLOR)"Compiling object files..."$(RESET)"\n"; \
	printf $(COLOR)"Creating dependency files..."$(RESET)"\n"; \
	fi
	
clean:
	$(RM) $(OBJ)
	$(RM) $(DEPENDS)
	make -s clean -C $(PATH_LIBFT)
	printf $(COLOR)"Removing all object files in src..."$(RESET)"\n"
	printf $(COLOR)"Removing all dependency files in src..."$(RESET)"\n"
	printf $(COLOR)"Removing all object files in libft..."$(RESET)"\n"

fclean:
	$(RM) $(OBJ)
	$(RM) $(DEPENDS)
	make -s fclean -C $(PATH_LIBFT)
	$(RM) $(NAME)
	printf $(COLOR)"Removing all object files in src..."$(RESET)"\n"
	printf $(COLOR)"Removing all dependency files in src..."$(RESET)"\n"
	printf $(COLOR)"Removing libft..."$(RESET)"\n"
	printf $(COLOR)"Removing $(NAME) executable..."$(RESET)"\n"

re:	
	make -s fclean 
	make -s all

################################################################################
#                                   Miscellaneous                              #
################################################################################

.PHONY:	all clean fclean re compile

.SILENT: 

################################################################################
#                           Dependency Management                              #
################################################################################

-include	$(DEPENDS)
