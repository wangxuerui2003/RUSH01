/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:18:54 by wxuerui           #+#    #+#             */
/*   Updated: 2023/02/20 15:01:16 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define USAGE_ERR "Usage: ./rush01 \"[args]\"\n"
# define ARGS_ERR "All args should be int and should be 4's multiple.\n"
# define NO_SOL "No solution for this set of args.\n"

typedef struct s_args {
	int	size;
	int	*up;
	int	*bot;
	int	*left;
	int	*right;
	int	**board;
}	t_args;

int	error_msg(char *s);
int	ft_strlen(char *s);
int	get_input(char *str_args, t_args *args);
int	solve(t_args *args, int pos);
void	ft_putnbr(int nbr);
void	print_board(t_args *args);

#endif