/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:57:25 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/27 16:11:02 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_path
{
	char	**path1;
	char	**path2;
	char	*cmd1;
	char	*cmd2;
}	t_path;

int		ft_strlen(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		no_env(void);
int		wrong_input(void);
int		check_args(char **av);
void	get_path(char **envp, t_path *path);
void	get_cmd(t_path *data, char *cmd1, char *cmd2);


#endif
