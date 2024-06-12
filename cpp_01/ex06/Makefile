NAME		=	harl_filter
CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC_FILES	=	main Harl

SRCS		=	$(addsuffix .cpp, $(SRC_FILES))
OBJS		=	$(addsuffix .o, $(SRC_FILES))

RESET		=	\033[0;39m
GREEN		=	\033[0;32m

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CPPFLAGS) $(OBJS) -o $@
			@printf "$(GREEN)Created executable: $(NAME)$(RESET)\n"

%.o:		%.cpp
			$(CC) $(CPPFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
