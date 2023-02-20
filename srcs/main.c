/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:18:41 by wxuerui           #+#    #+#             */
/*   Updated: 2023/02/20 15:47:30 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	print_board(t_args *args)
{
	int	i;

	i = -1;
	write(STDOUT_FILENO, " | ", 3);
	while (++i < args->size)
	{
		ft_putnbr(args->up[i]);
		write(STDOUT_FILENO, " ", 1);
	}
	write(STDOUT_FILENO, "| \n", 4);
	write(STDOUT_FILENO, "-+---------+-\n", 14);
	for (int i = 0; i < args->size; i++)
	{
		ft_putnbr(args->left[i]);
		write(STDOUT_FILENO, "| ", 2);
		for (int j = 0; j < args->size; j++)
		{
			ft_putnbr(args->board[i][j]);
			write(STDOUT_FILENO, " ", 1);
		}
		write(STDOUT_FILENO, "|", 1);
		ft_putnbr(args->right[i]);
		write(STDOUT_FILENO, "\n", 1);
	}
	write(STDOUT_FILENO, "-+---------+-\n", 14);
	i = -1;
	write(STDOUT_FILENO, " | ", 3);
	while (++i < args->size)
	{
		ft_putnbr(args->bot[i]);
		write(STDOUT_FILENO, " ", 1);
	}
	write(STDOUT_FILENO, "| \n", 4);	
}

int	main(int ac, char **av)
{
	t_args	args;

	if (ac != 2)
		return (error_msg(USAGE_ERR));
	if (get_input(av[1], &args) == 0)
		return (error_msg(ARGS_ERR));
	if (solve(&args, 0) == 0)
		return (error_msg(NO_SOL));
	print_board(&args);
	free(args.up);
	free(args.bot);
	free(args.left);
	free(args.right);
	for (int i = 0; i < args.size; i++)
		free(args.board[i]);
	free(args.board);

	// system("leaks rush01");
	return (0);
}
