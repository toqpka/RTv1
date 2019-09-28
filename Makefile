# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 17:42:35 by gwaymar-          #+#    #+#              #
#    Updated: 2019/09/28 06:31:37 by gwaymar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := RTv1

# SRCS files
SRCS_PATH := ./srcs
SRCS_FILES := main.c init_func.c color_pixel.c framebuffer.c framebuf_color.c framebuf_color_vec.c\
							render/draw.c\
							render/sdl_loop.c\
							scene/scene1.c\
							scene/scene2.c\
							scene/scene3.c\
							vectors/rotate_vec.c\
							vectors/op_vec.c\
							vectors/new_vec.c\
							vectors/normal_vec.c
SRCS := $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

# OBJ files
OBJECTS_PATH := ./objs
OBJECTS_FILES := $(SRCS_FILES:.c=.o)
OBJECTS := $(addprefix $(OBJECTS_PATH)/, $(OBJECTS_FILES))
SUB_DIR_OBJ := $(patsubst %, $(OBJECTS_PATH)/%, $(notdir $(shell find $(SRCS_PATH) -type d -not -path $(SRCS_PATH))))

# cc FLAGS
CC := gcc
#CCFLAGS := -Wall -Wextra -Werror
CCFLAGS := -g

# SDL2
SDL_PATH := ./sdl2/Frameworks
SDL_NAME := SDL2
SDL_INC := -I $(addprefix $(SDL_PATH)/,SDL2.framework/Versions/A/Headers)
SDL_LNK := -framework SDL2 -F $(SDL_PATH)
SDL_rpath := -rpath $(SDL_PATH)
SDL_IMAGE_INC := -I $(addprefix $(SDL_PATH)/,SDL2_image.framework/Versions/A/Headers/)
SDL_TTF_INC := -I $(addprefix $(SDL_PATH)/,SDL2_ttf.framework/Versions/A/Headers)
SDL_MIXER_INC := -I $(addprefix $(SDL_PATH)/,SDL2_mixer.framework/Versions/A/Headers)
SDL_IMAGE_LNK := -framework SDL2_image -F $(SDL_PATH)
SDL_TTF_LNK := -framework SDL2_ttf -F $(SDL_PATH)
SDL_MIXER_LNK := -framework SDL2_mixer -F $(SDL_PATH)
SDL2 := $(SDL_rpath) $(SDL_LNK) $(SDL_IMAGE_LNK) $(SDL_TTF_LNK) $(SDL_MIXER_LNK)

# libft
LIB_PATH := ./lib/libft
LIB_NAME := LibFT
LIB := $(addprefix $(LIB_PATH)/,libft.a)
LIB_INC := -I $(LIB_PATH)
LIB_LNK := -L $(LIB_PATH) -l ft

# include lib and minilibX
INCLUDES := $(LIB_INC) $(SDL_INC) $(SDL_IMAGE_INC) $(SDL_TTF_INC) $(SDL_MIXER_INC) -I ./includes
HEADER := ./includes/rtv1.h ./includes/rtv1_prototypes.h\
					./includes/rtv1_structs.h ./includes/rtv1_vec3.h

# console colors
RESET := \033[0m
RED := \033[31m
BLUE := \033[34m
YELLOW := \033[33m
GREEN := \033[32m
INVERT := \033[7m
SUCCESS := [$(GREEN)✓$(RESET)]
SUCCESS_OK := [$(GREEN)OK$(RESET)]
# clear_row (delete all symymbols)
CLEAR_ROW := @echo "\033[1A\033[K\033[1A"

#	First target
all: $(NAME)

$(OBJECTS): $(OBJECTS_PATH)/%.o: $(SRCS_PATH)/%.c $(HEADER) | $(SUB_DIR_OBJ) $(OBJECTS_PATH)
	@echo -n ' $@: '
	@$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(SUCCESS)"

$(OBJECTS_PATH):
	@mkdir -p $(OBJECTS_PATH) > /dev/null

$(SUB_DIR_OBJ):
	@mkdir -p $(OBJECTS_PATH) $(SUB_DIR_OBJ) > /dev/null

$(LIB): | $(HEADER)
	@echo "$(RED) > $(RESET)Compilation $(NAME)"

$(NAME): $(LIB) $(OBJECTS) $(HEADER)
	@echo "$(YELLOW) Creating OBJ .o $(RESET)$(SUCCESS_OK)"
	@echo "$(YELLOW) $(LIB_NAME)           $(RESET)[$(YELLOW)Compiling...$(RESET)]"
	@make -C $(LIB_PATH) > /dev/null
	$(CLEAR_ROW)
	@echo "$(YELLOW) $(LIB_NAME)           $(RESET)$(SUCCESS_OK)"
	@echo "$(YELLOW) $(NAME)            $(RESET)[$(YELLOW)Compiling...$(RESET)]"
	@$(CC) $(SDL2) $(CCFLAGS) $(OBJECTS) $(LIB_LNK) -o $(NAME)
	$(CLEAR_ROW)
	@echo "$(YELLOW) $(NAME)            $(RESET)$(SUCCESS_OK)"
	@echo "$(RED) > $(BLUE)Compilation is ended$(RESET)"

#	Removing objects
clean:
	@echo "$(RED)removing  object files - ...$(RESET)"
	@make -C $(LIB_PATH) clean > /dev/null
	@rm -rf $(OBJECTS_PATH) > /dev/null
	$(CLEAR_ROW)
	@echo "$(RED)removing  object files - done$(RESET)"

#	Removing objects and project_launcher
fclean: clean
	@echo "$(RED)removing  $(NAME) - ...$(RESET)"
	@make -C $(LIB_PATH) fclean > /dev/null
	@rm -rf $(NAME) > /dev/null
	$(CLEAR_ROW)
	@echo "$(RED)removing  $(NAME) - done$(RESET)"

#	All removing then compiling
re: fclean all
