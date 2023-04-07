/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:59:44 by robegarc          #+#    #+#             */
/*   Updated: 2023/04/06 17:57:19 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/global.h"
#include "../incl/functions.h"

int	check_argus(t_cmd *cmd, char c, char next_c)
{
	if (c == '&')
	{
		if (next_c == '&')
			cmd->arg_id = double_and;
	}
	else if (c == '|')
			cmd->arg_id = pipe_line;
	else if (c == '|' && next_c == '|')
			cmd->arg_id = or;
	else if (c == '<')
	{
		if (next_c == '<')
			cmd->arg_id = heredoc;
		else
			cmd->arg_id = redirection_in;
	}
	else if (c == '>')
	{
		if (next_c == '>')
			cmd->arg_id = append;
		else
			cmd->arg_id = redirection_out;
	}
	return (0);
}

int init(t_args *ptr, int j)
{
	t_cmd	*cmd;
	int		i;
	int		x;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	i = -1;
	x = -1;
	while (ptr->mat[j][++i])
	{
		cmd->param = ptr->mat[j];
		//fix the check argus i don't get the right parameter
		check_argus(cmd, ptr->mat[j][i], ptr->mat[j][i + 1]);
		printf("\t\tthe %d character-> [%c]\n", i, ptr->mat[j][i]);
	}
	printf("cmd.id-> %d\n", cmd->arg_id);
	return (0);
}