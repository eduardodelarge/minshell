/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 02:01:09 by anjose-d          #+#    #+#             */
/*   Updated: 2022/08/26 11:24:52 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <signal.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

# include <sys/wait.h>
// waitpid

# include <dirent.h>
// opendir

# define PROMPT_STR "$> "

// builtins
# define ECHO "echo"
# define CD "cd"
# define PWD "pwd"
# define EXPORT "export"
# define UNSET "unset"
# define ENV "env"
# define EXIT "exit"

// tk_types
# define TK_WORD "word"
# define TK_GREAT "great"
# define TK_LESS "less"
# define TK_PIPE "pipe"
# define TK_AND "and"
# define TK_ASYNC "async"
# define TK_OR "or"
# define TK_DLESS "dless"
# define TK_DGREAT "dgreat"
# define TK_FILE "file"

// cmd types
# define CMD_COMMAND "Command"
# define CMD_PIPE "Pipeline"
# define CMD_AND_OR "LogicalExpression"

// expansion types
# define EXP_ENVVAR "envvar"
# define EXP_EXIT_STATUS "exit-status"

// error msgs
# define ERR_FNOEXST "No such file or directory"
# define ERR_NOPERM "Permission denied"
# define ERR_HDOC "minishell: warning: here-document delimited by end-of-file\n"
# define PIPE_READ 0
# define PIPE_WRITE 1

extern int	g_exit_status;

typedef struct s_redir
{
	int	fdin;
	int	fdout;
}				t_redir;

typedef struct s_expansion
{
	int		start;
	int		end;
	char	*param;
	char	*type;
}			t_expansion;

typedef struct s_lexem
{
	char		*text;
	char		*type;
	t_expansion	*expansion;
}			t_lexem;

typedef struct s_token
{
	t_lexem		*lexem;
	t_lexem		*file;
	t_lexem		*eof;
}				t_token;

typedef struct s_cmdline
{
	char	*type;
	t_token	*name;
	t_list	*suffix;
	char	*raw_input;

	t_list	*pipeline;

	t_list	*left;
	t_list	*right;

	t_redir	*redir;

	t_list	*here_doc; // t_token
}				t_cmd;

typedef struct s_envp
{
	char	*name;
	char	*value;
}				t_envp;

// tokenizer & parser
int			token_count(char *input);
int			get_token_size(char *input);

// parser main function
t_cmd		*get_cmdtable(char *input, t_list *envp);

char		**tokenizer_split(char *input);
t_list		*lexem_tagging(char **tokens_split);
t_list		*get_tokens(t_list *lexems);
t_cmd		*parser_cmdtable_noop(t_list *tokens);
t_cmd		*parser_cmdtable_pipeline(t_list *lst_tokens);

// parser lex_expander
void		ft_lex_expander(t_list **lst_lexems, t_list *envp);

// exec
int			exec_cmdline(t_cmd *cmd_table, t_list **envp);
void		perform_execve_normal(t_cmd *cmdtable, t_list **envp);
void		perform_execve_redir(t_cmd *cmdtable, t_list **envp);

// exec_cmdline_builtin
int			exec_builtin(t_cmd *cmdline, t_list **envp);
// exec_cmd
void		exec_cmd(t_cmd *cmdtable, t_list **envp);
// exec_here_doc
int			here_doc(t_list *lst_here_doc);

// utils1
int			is_operator(char c);
int			is_quote_apst(char c);
int			is_redir_type(char *type);
int			is_expansion(char *text);
int			is_builtin(char *cmd);
// utils2
char		**lst2mtx_envp(t_list *records);
char		*ft_skip_space(char *str);
char		*ft_rm_quotation(char *str);
int			cmdline_has_redir(t_cmd *cmdline);
// utils3
char		**cmdline2mtx_normal(t_cmd *cmdtable);
char		**cmdline2mtx_redir(t_cmd *cmdtable);
void		skip_redir_tokens(t_list **suffix);
// utils4
void		printf_export_no_opt(t_envp *envvar, int fd);
void		close_fds(int fdin, int fdout);
void		rm_quote_from_lexems(t_list **lst_lexems);
char		*rm_break_line(char **input);
// utils_env
void		att_oldpwd(t_list **envp);
void		att_pwd(t_list **envp);
char		*get_envvar_value(char *param, t_list *envp);
t_envp		*find_envvar(t_list *envp, char *varname);

// utils exec
int			has_path(char *cmd);
char		*find_path(char *cmd, char *path_value);
char		*get_path(char *cmd, t_list *envp);

// utils open files
t_redir		*open_files(char *file, char *tk_type);
t_redir		*there_is_redir(t_list *suffix);

// utils pipeline
void		save_std_fds(t_cmd **cmdtable);
void		restart_terminal(t_cmd *cmdtable);
void		pipe_to_stdfd(int pipefd, int stdfd);

// utils here_doc
t_token	*cmdtable_get_heredoc(t_list *lst_tokens);
t_list	*cmdtable_get_hdoc_lst(t_list *lst_tokens);

// free functions
void		free_t_lexem(void *lexem);
void		free_t_token(void *token);
void		free_t_expansion(void *expansion);
void		free_t_cmd(void *cmdtable);
void		free_t_envp(void *envp);

// init functions
t_token		*token_init(t_lexem *lex_cur);
t_cmd		*cmd_init(char *type);
t_envp		*envp_init(char *envvar_name);
t_redir		*redir_init(void);
// init lexem
t_lexem		*lexem_init(char *text);
// init expansion
t_expansion	*expansion_init(char *lex_text);
// init envp
t_list		*init_envp_list(char *envp[]);

// cpy functions
t_lexem		*lexem_cpy(t_lexem *lexem);
t_expansion	*expansion_cpy(t_expansion *expansion);
t_token		*token_cpy(t_token *token);

// check error
int			check_syntax_error(t_list *lst_lexems);

// errors
void		printf_export_error(char *param);
void		printf_unset_error(char *param);
int			printf_exit_error(char *param, int exit_status);
void		printf_cd_error(void);
void		printf_exec_error(char *param, int exit_status);
// exec_errors
void		pipe_error(void);
void		fork_error(void);
int			printf_openfile_error(char *file, char *msg);
// signal
void		setup_signals(void);
// builtins
int			ft_echo(t_list *param, int fd, char *raw_input);
int			ft_cd(t_list *suffix, t_list **envp);
int			ft_pwd(int fd);
int			ft_export(t_list *suffix, t_list **envp, int fd);
int			ft_unset(t_list *suffix, t_list **envp);
int			ft_exit(t_list *suffix);
int			ft_env(t_list *envp, int fd);

#endif
