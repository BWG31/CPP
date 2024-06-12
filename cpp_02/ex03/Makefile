NAME		=	bsp
CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJS_DIR	=	objs/

SRC_FILES	=	main Fixed Point bsp tests

SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILES)))
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

RESET		=	\033[0;39m
GREEN		=	\033[0;32m

all:		$(NAME)

$(NAME):	$(OBJS_DIR) $(OBJS)
			$(CC) $(CPPFLAGS) $(OBJS) -o $@
			@printf "$(GREEN)Created executable: $(NAME)$(RESET)\n"

$(OBJS_DIR)%.o:		$(SRC_DIR)%.cpp
			$(CC) $(CPPFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJS_DIR):
			@mkdir -p $@

clean:
			rm -rf $(OBJS_DIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
