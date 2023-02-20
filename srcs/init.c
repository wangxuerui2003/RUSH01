/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:31:31 by wxuerui           #+#    #+#             */
/*   Updated: 2023/02/20 15:33:56 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	init_board(t_args *args)
{
	int	i;
	int	j;

	args->board = malloc(sizeof(int *) * args->size);
	if (args->board == NULL)
		return (0);
	i = -1;
	while (++i < args->size)
	{
		args->board[i] = malloc(sizeof(int) * args->size);
		if (args->board[i] == NULL)
			return (0);
		j = -1;
		while (++j < args->size)
			args->board[i][j] = 0;
	}
	return (1);
}

static int	parse_args(t_args *args, int *temp_arr)
{
	int	i;

	args->up = malloc(args->size * sizeof(int));
	args->bot = malloc(args->size * sizeof(int));
	args->left = malloc(args->size * sizeof(int));
	args->right = malloc(args->size * sizeof(int));
	if (args->up == NULL || args->bot == NULL
		|| args->left == NULL || args->right == NULL)
		return (0);
	i = -1;
	while (++i < args->size * 4)
	{
		if (i < args->size)
			args->up[i] = temp_arr[i];
		else if (i < args->size * 2)
			args->bot[i % args->size] = temp_arr[i];
		else if (i < args->size * 3)
			args->left[i % args->size] = temp_arr[i];
		else
			args->right[i % args->size] = temp_arr[i];
	}
	free(temp_arr);
	return (1);
}

static int	check_input(char *str_args, t_args *args)
{
	int	i;
	int	len;
	int	num_args;

	i = -1;
	len = ft_strlen(str_args);
	num_args = 0;
	while (++i < len)
	{
		if (str_args[i] != ' ')
		{
			if (str_args[i] < '0' || str_args[i] > '9')
				return (0);
			num_args++;
		}
	}
	if (num_args % 4 != 0)
		return (0);
	args->size = num_args / 4;
	return (1);
}

int	get_input(char *str_args, t_args *args)
{
	int	*temp_arr;
	int	i;
	int	j;

	if (check_input(str_args, args) == 0)
		return (0);
	temp_arr = malloc(args->size * 4 * sizeof(int));
	if (temp_arr == NULL)
		return (0);
	i = -1;
	j = 0;
	while (str_args[++i] != 0)
		if (str_args[i] != ' ')
			temp_arr[j++] = str_args[i] - '0';
	if (parse_args(args, temp_arr) == 0)
		return (0);
	if (init_board(args) == 0)
		return (0);
	return (1);
}
