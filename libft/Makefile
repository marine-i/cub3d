NAME = libft.a

HEADER = include/libft.h

CC = cc

CFLAGS = -Wall -Werror -Wextra -Iinclude -ggdb

SRCDIR = src/
OBJDIR = obj/

SRCS =  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_tolower.c ft_toupper.c \
		ft_atoi.c ft_strchr.c ft_strncmp.c ft_memset.c ft_strrchr.c ft_bzero.c ft_memcpy.c ft_strlcat.c ft_strlcpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_strdup.c ft_calloc.c ft_substr.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_itoa.c \
		ft_split.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstclear.c ft_lstmap.c \
		ft_printf.c ft_printhex.c ft_printnbr.c ft_printstr.c

SRCS_WITH_SRCDIR = $(addprefix $(SRCDIR), $(SRCS))
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS_WITH_SRCDIR))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re