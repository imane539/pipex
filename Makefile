CFLAGS = -Wall -Werror -Wextra

SRC = ft_pipex.c \
ft_pipex_utils.c \

OBJECTS =$(SRC:.c=.o)
AR = ar rcs

NAME = libpipex.a

all:$(NAME)

$(NAME):$(OBJECTS)
	$(AR) $(NAME) $^

clean :
	rm -f $(OBJECTS) 
	
fclean : clean 
	rm -f $(NAME)

re : fclean all

# .PHONY:re all fclean clean 

.SECONDARY : $(OBJECTS)