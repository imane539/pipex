CFLAGS = -Wall -Werror -Wextra

SRC = ft_pipex.c \
ft_pipex_utils.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_strncmp.c \
ft_strlen.c \
ft_putunsigned.c \
ft_easy.c \
ft_medium.c \
ft_hard.c \
ft_hex.c \
ft_printf.c \
ft_format.c \
ft_check.c \
ft_address.c \

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