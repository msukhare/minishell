/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:25:11 by msukhare          #+#    #+#             */
/*   Updated: 2018/02/23 12:57:13 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/include/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>

typedef struct stat	t_stat;
typedef struct		s_cmd
{
	char			cara;
	struct s_cmd	*next;
	struct s_cmd	*back;
}					t_cmd;
typedef struct		s_env
{
	char			*var;
	struct s_env	*next;
}					t_env;
t_cmd				*ft_creatlist(char buff, t_cmd *back_lst);
void				ft_dellist(t_cmd **begin_list);
void				ft_execcmd(t_cmd **begin_list, t_env **begin_env);
char				*ft_getcmd(t_cmd **begin_list);
char				**ft_getarg(t_cmd **begin_list);
void				ft_freetab(char **tab);
void				ft_cpag(char *dest, t_cmd **begin_list);
t_env				*ft_createnv(char **env);
int					ft_strccmp(char *s1, char *s2, char c);
int					ft_env(t_env *env, char **arg);
int					ft_setenv(t_env *env, char **arg);
t_env				*ft_creatvar(char *str);
void				ft_unsetenv(char **arg, t_env **env);
void				ft_echo(char **arg);
int					ft_cd(char **arg, t_env *env);
int					ft_execbin(char *cmd, t_env *env, char **arg);
t_env				*ft_generatenv(void);
int					ft_lstlen(t_env *bg_lst);
char				*ft_getvar_in_env(char *str, t_env *env, int error);
char				*ft_getpath(char **arg, int size, t_env *env);
char				*ft_getoldpwd(t_env *env);
void				ft_dellst(t_env *begin_list);
t_env				*ft_cpylst(t_env *env);
void				ft_printenv(t_env *env);
int					ft_check_var(char *str);
t_env				*ft_check_path(t_env *env);
int					ft_checkbin(char *path_cmd, char *cmd);
void				ft_exit_read(t_env **begin_env, int ex, t_cmd **begin_list);
void				ft_print_error(char *cmd);
int					ft_puterror(t_cmd **bg_lst);
void				ft_exitshell(char *cmd, char **arg, t_env **env, \
		t_cmd **bg_l);
void				ft_putloca(t_env **begin_env, t_cmd **begin_list);
int					ft_check_arg_cd(int size, char **arg);
int					ft_checkaccess(char *path);
int					ft_check_is_dir(char *path);
char				*ft_getdefault_pwd(void);
#endif
