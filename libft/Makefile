# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/03 00:12:28 by anjose-d          #+#    #+#              #
#    Updated: 2022/08/13 20:26:29 by anjose-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
FLAGS	= -Wall -Wextra -Werror
CC		= gcc

INCLUDE	=	./includes
SRCDIR	=	srcs
HEADER	=	$(addprefix $(INCLUDE)/, libft.h)
SOURCES	= 	ft_atoi.c \
		  	ft_strlen.c \
		  	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_bzero.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c ft_split_idx.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putchar.c \
			ft_putstr.c \
			get_next_line.c \
			ft_extcheck.c \
			ft_str_find_idx.c ft_strndup.c ft_is_numeric.c \
			ft_power.c ft_nbrsize.c ft_mtxlen.c \
			ft_destroy_matrix.c	ft_atoi_llong.c

SRCSBNS	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstget.c \
			ft_lstrm_node.c \
			ft_dlstadd_back.c ft_dlstadd_front.c ft_dlstclear.c \
			ft_dlstlast.c ft_dlstnew.c ft_dlstrm_node.c ft_dlstsize.c		

PRINTF_DIR	=	$(addprefix $(SRCDIR)/, ft_printf)
PRINTF_SRCS	=	ft_printf.c \
				ft_printf_utils.c \
				ft_convert_p.c \
				ft_convert_x.c \
				ft_convert_u.c \
				ft_convert_d_i.c \
				ft_convert_c.c \
				ft_convert_s.c \

SRCS_PATH	= 	$(addprefix $(SRCDIR)/, $(SOURCES))
SRCSBNS_PATH=	$(addprefix $(SRCDIR)/, $(SRCSBNS))

OBJS_DIR	=	./objs
OBJECTS		=	$(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))
BONUS_OBJS	=	$(addprefix $(OBJS_DIR)/, $(SRCSBNS:.c=.o))
PRINTF_OBJS	=	$(addprefix $(OBJS_DIR)/, $(PRINTF_SRCS:.c=.o))

# LIBFT OBJS
$(OBJS_DIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@

# PRINTF OBJS
$(OBJS_DIR)/%.o: $(PRINTF_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME): $(OBJECTS) $(BONUS_OBJS) $(PRINTF_OBJS)
	ar -rcs $(NAME) $(OBJECTS) $(BONUS_OBJS) $(PRINTF_OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJECTS) $(BONUS_OBJS) $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
