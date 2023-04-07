/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:59:46 by robegarc          #+#    #+#             */
/*   Updated: 2023/04/06 17:41:41 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include "libft/libft.h"

# define MINISHELL "\033[0;35mMinishell\033[0m >>> "

enum e_flags
{
	pipe_line = 1,
	double_and = 2,
	or = 3,
	redirection_in = 4,
	redirection_out = 5,
	heredoc = 6,
	append = 7,
};

typedef struct s_args
{
	char	**mat;
	char	*line;
	char	*str;
	int		i;
	int		j;
	int		arg_id;
}              t_args;

typedef struct s_cmd
{
	char			**mat;
	char			*line;
	char			*param;
	int				i;
	int				j;
	int				arg_id;
	struct s_cmd	*nxt;
	struct s_cmd	*prv;
}              t_cmd;

#endif