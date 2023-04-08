/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:59:46 by robegarc          #+#    #+#             */
/*   Updated: 2023/04/08 16:30:32 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

int		check_flags1(char *s, t_args *ptr);
int		init(char *ptr, t_args *args);

void	free_matrix(t_cmd *cmd);

#endif