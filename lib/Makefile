SHELL			=	/bin/bash

NAME			=	libft.a

NOCOL			=	\033[0m
RED				=	\033[1;31m
ORG				=	\033[0;33m
YEL				=	\033[1;33m
GRN				=	\033[1;32m
BLU				=	\033[0;34m
CYN				=	\033[0;36m

SRCS			=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
					ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
					ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
					ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
					ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
					ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
					ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c \
					ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
					ft_lstiter.c ft_lstmap.c ft_get_max.c ft_get_min.c\
					ft_strupper.c ft_strdup_limit.c ft_itoa_base.c \
					ft_itoa_base_llu.c ft_itoa_base_uint.c \
					get_next_line.c ft_isspace.c ft_split_isspace.c \
					ft_atof.c ft_power.c ft_freetab.c ft_ternary.c \
					ft_swap_double.c ft_strcmp.c ft_putchar.c

OBJS			=	$(SRCS:.c=.o)

CFLAGS			=	-g -Wall -Wextra -Werror

HEADER			=	libft.h

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)
				@echo -e "$(GRN) => Success! $(NOCOL)"

%.o: %.c		$(HEADER)
				@echo -e -n "$(ORG)*$(NOCOL)"
				@gcc $(CFLAGS) -include $(HEADER) -o $@ -c $<

clean:
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
