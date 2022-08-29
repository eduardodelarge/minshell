# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 17:53:09 by anjose-d          #+#    #+#              #
#    Updated: 2022/08/26 12:13:51 by anjose-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MAIN VARIABLES
NAME		=	minishell
CC			=	gcc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror

# INCLUDES
## Main Project
INCS		=	minishell.h
INCS_DIR	=	./includes
MAIN_HEADER	=	$(addprefix $(INCS_DIR)/, $(INCS))

## Libft
LIBFT		=	ft
LIBFT_DIR	=	./libft
INCS_LFT	=	libft.h
LIBFT_LINK	=	-L$(LIBFT_DIR) -l$(LIBFT)

## Readline
RDLINE_LNK	=	-lreadline

# ALL INCLUDES IN THE PROJECT
INC_FLAGS	=	-I $(INCS_DIR) -I $(LIBFT_DIR)/includes 

# SOURCES
SRCS_DIR	=	./srcs
MAIN_SRC	=	main.c
MAIN_SRC_TST=	main_tests2.c
#  signals
SIGNAL_DIR	=	signals
SIGNAL_SRC	=	setup_signals.c
#  builtins
BUILTIN_DIR	=	builtins
BUILTIN_SRCS=	cd.c export.c env.c echo.c unset.c pwd.c exit.c
#  parser
PARSER_DIR	=	parser
PARSER_SRCS	=	get_cmdtable.c \
				parser_token_count.c parser_token_splitter.c parser_get_token_size.c \
				lexem_tagging.c parser_get_tokens.c parser_lex_expander.c \
				parser_cmdtable_noop.c parser_cmdtable_pipeline.c \
				check_syntax_error.c
#  utils
UTILS_DIR	=	utils
UTILS_SRCS	=	utils1.c utils2.c utils3.c utils4.c \
				utils_env.c utils_exec.c utils_open_files.c utils_pipeline.c utils_here_doc.c
#  init and free
INITFREE_DIR=	init_free
INITFREE_SRC=	free_functions.c init_envp_list.c cpy_functions.c \
				init_lexem.c init_expansion.c init_functions.c
#  exec
EXEC_DIR	=	exec
EXEC_SRCS	=	exec_cmdline.c exec_cmd.c \
				exec_perform_execve_normal.c exec_perform_execve_redir.c \
				exec_cmdline_builtin.c exec_here_doc.c
#  errors
ERRORS_DIR	=	errors
ERRORS_SRCS	=	printf_errors.c exec_error.c
SRCS		=	$(MAIN_SRC) \
				$(addprefix $(PARSER_DIR)/, $(PARSER_SRCS)) \
				$(addprefix $(BUILTIN_DIR)/, $(BUILTIN_SRCS)) \
				$(addprefix $(UTILS_DIR)/, $(UTILS_SRCS)) \
				$(addprefix $(INITFREE_DIR)/, $(INITFREE_SRC)) \
				$(addprefix $(EXEC_DIR)/, $(EXEC_SRCS)) \
				$(addprefix $(SIGNAL_DIR)/, $(SIGNAL_SRC)) \
				$(addprefix $(ERRORS_DIR)/, $(ERRORS_SRCS))

SRCS_TEST	=	$(MAIN_SRC_TST) \
				$(addprefix $(PARSER_DIR)/, $(PARSER_SRCS)) \
				$(addprefix $(BUILTIN_DIR)/, $(BUILTIN_SRCS)) \
				$(addprefix $(UTILS_DIR)/, $(UTILS_SRCS)) \
				$(addprefix $(INITFREE_DIR)/, $(INITFREE_SRC)) \
				$(addprefix $(EXEC_DIR)/, $(EXEC_SRCS)) \
				$(addprefix $(SIGNAL_DIR)/, $(SIGNAL_SRC)) \
				$(addprefix $(ERRORS_DIR)/, $(ERRORS_SRCS))

SRCS_PTH	=	$(addprefix $(SRCS_DIR)/, $(SRCS))
SRCS_TST_PTH=	$(addprefix $(SRCS_DIR)/, $(SRCS_TEST))

# OBJS
OBJS_DIR	=	./objs
OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
DIR_GUARD	=	mkdir -p $(@D)

# EXPLICIT COMPILATION OF THE OBJECTS
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(DIR_GUARD)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

# TARGETS
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIBFT_LINK) $(RDLINE_LNK) -o $@ 

clean:
	$(RM) $(OBJS_DIR) teste valgrind debug
	
fclean:	clean
	@make $@ -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

debug:
	@make -C $(LIBFT_DIR)
	$(CC) -g $(CFLAGS) $(INC_FLAGS) $(SRCS_PTH) $(LIBFT_LINK) $(RDLINE_LNK) -o $@
	gdb --tui ./$@ #set follow-fork-mode child

valgrind:
	@make -C $(LIBFT_DIR)
	$(CC) -g $(CFLAGS) $(INC_FLAGS) $(SRCS_PTH) ./libft/srcs/ft_destroy_matrix.c $(LIBFT_LINK) $(RDLINE_LNK) -o $@
	valgrind --leak-check=full --track-fds=yes --suppressions=readline.supp ./$@
# --track-origins=yes crashing instra's execution
git: fclean
	git add .
	git commit -m "$m"
	git push

teste:
	@make -C $(LIBFT_DIR)
	$(CC) -g $(SRCS_TST_PTH) $(INC_FLAGS) $(LIBFT_LINK) $(RDLINE_LNK) -o $@
	./$@

.PHONY: all clean fclean re git teste valgrind debug