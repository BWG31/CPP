NAME		=	violence
CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	inc/

SRC_FILES	=	main Weapon HumanA HumanB

SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILES)))
OBJS		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

RESET		=	\033[0;39m
GREEN		=	\033[0;32m

all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS)
			$(CC) $(CPPFLAGS) $(OBJS) -o $@
			@printf "$(GREEN)Created executable: $(NAME)$(RESET)\n"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
				$(CC) $(CPPFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
			mkdir -p $@

clean:
			rm -rf $(OBJ_DIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
