CFLAGS = -Wall -Werror -Wextra 


LIB = ft_printf/libft/ft_isalpha.c \
ft_printf/libft/ft_isdigit.c \
ft_printf/libft/ft_isalnum.c \
ft_printf/libft/ft_isascii.c \
ft_printf/libft/ft_isprint.c \
ft_printf/libft/ft_strlen.c \
ft_printf/libft/ft_memset.c \
ft_printf/libft/ft_bzero.c \
ft_printf/libft/ft_strlcpy.c \
ft_printf/libft/ft_strlcat.c \
ft_printf/libft/ft_toupper.c \
ft_printf/libft/ft_tolower.c \
ft_printf/libft/ft_strchr.c \
ft_printf/libft/ft_strrchr.c \
ft_printf/libft/ft_strncmp.c \
ft_printf/libft/ft_strnstr.c \
ft_printf/libft/ft_atoi.c \
ft_printf/libft/ft_memcpy.c \
ft_printf/libft/ft_memmove.c \
ft_printf/libft/ft_memchr.c \
ft_printf/libft/ft_memcmp.c \
ft_printf/libft/ft_calloc.c \
ft_printf/libft/ft_strdup.c \
ft_printf/libft/ft_substr.c \
ft_printf/libft/ft_strjoin.c \
ft_printf/libft/ft_strtrim.c \
ft_printf/libft/ft_split.c \
ft_printf/libft/ft_itoa.c \
ft_printf/libft/ft_strmapi.c \
ft_printf/libft/ft_striteri.c \
ft_printf/libft/ft_putchar_fd.c \
ft_printf/libft/ft_putstr_fd.c \
ft_printf/libft/ft_putendl_fd.c \
ft_printf/libft/ft_putnbr_fd.c \
ft_printf/libft/ft_lstnew_bonus.c \
ft_printf/libft/ft_lstadd_front_bonus.c \
ft_printf/libft/ft_lstsize_bonus.c \
ft_printf/libft/ft_lstlast_bonus.c \
ft_printf/libft/ft_lstadd_back_bonus.c \
ft_printf/libft/ft_lstdelone_bonus.c \
ft_printf/libft/ft_lstclear_bonus.c \
ft_printf/libft/ft_lstiter_bonus.c \
ft_printf/libft/ft_lstmap_bonus.c \

PRINTF = ft_printf/ft_putunsigned.c \
ft_printf/ft_easy.c \
ft_printf/ft_medium.c \
ft_printf/ft_hard.c \
ft_printf/ft_hex.c \
ft_printf/ft_printf.c \
ft_printf/ft_format.c \
ft_printf/ft_check.c \
ft_printf/ft_address.c \

SRC =ft_pipex.c \
ft_pipex_utils.c \

SRCB = ft_pipex_bonus.c \
ft_pipex_utils_bonus.c \
ft_cmd_bonus.c \
ft_here_doc_bonus.c \

OBJECTS =$(SRC:.c=.o) $(LIB:.c=.o) $(PRINTF:.c=.o)

OBJECTSB =$(SRCB:.c=.o) $(LIB:.c=.o) $(PRINTF:.c=.o)

PROG = pipex

all:$(PROG)

$(PROG):$(OBJECTS)
	cc $(CFLAGS)  $^ -o $(PROG)

bonus:$(OBJECTSB)
	cc $(CFLAGS)  $^ -o $(PROG)

clean :
	rm -f $(OBJECTS) $(OBJECTSB) 

fclean : clean 
	rm -f $(PROG)

re : fclean all

.PHONY: clean 

.SECONDARY : $(OBJECTS) $(OBJECTSB)
# -fsanitize=address -g3