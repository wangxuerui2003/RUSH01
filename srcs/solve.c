/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:18:16 by wxuerui           #+#    #+#             */
/*   Updated: 2023/02/20 15:34:52 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	valid_col(t_args *args, int col)
{
	int	see;
	int	highest;
	int	i;

	see = 1;
	i = -1;
	highest = args->board[0][col];
	while (++i < args->size)
	{
		if (args->board[i][col] == 0)
			return (-1);
		if (args->board[i][col] > highest)
		{
			highest = args->board[i][col];
			see++;
		}
	}
	if (see != args->up[col])
		return (0);
	see = 1;
	i = args->size;
	highest = args->board[args->size - 1][col];
	while (--i >= 0)
		if (args->board[i][col] > highest)
		{
			highest = args->board[i][col];
			see++;
		}
	if (see != args->bot[col])
		return (0);
	return (1);
}

static int	valid_row(t_args *args, int row)
{
	int	see;
	int	highest;
	int	i;

	see = 1;
	i = -1;
	highest = args->board[row][0];
	while (++i < args->size)
	{
		if (args->board[row][i] == 0)
			return (-1);
		if (args->board[row][i] > highest)
		{
			highest = args->board[row][i];
			see++;
		}
	}
	if (see != args->left[row])
		return (0);
	see = 1;
	i = args->size;
	highest = args->board[row][args->size - 1];
	while (--i >= 0)
		if (args->board[row][i] > highest)
		{
			highest = args->board[row][i];
			see++;
		}
	if (see != args->right[row])
		return (0);
	return (1);
}

static int	valid(t_args *args, int pos)
{
	int	row;
	int	col;
	int	i;

	row = pos / args->size;
	col = pos % args->size;
	i = -1;
	while (++i < args->size)
	{
		if (i != col)
			if (args->board[row][i] == args->board[row][col])
				return (0);
		if (i != row)
			if (args->board[i][col] == args->board[row][col])
				return (0);
	}
	if (valid_row(args, row) && valid_col(args, col))
	{
		if (valid_row(args, row) == 1 && valid_col(args, col) == 1
			&& pos == args->size * args->size - 1)
			return (42);
		return (1);
	}
	return (0);
}

int	solve(t_args *args, int pos)
{
	int	try;

	if (valid(args, pos) == 42)
		return (1);
	try = 0;
	// print_board(args);
	// usleep(100000);
	while (++try < args->size + 1)
	{
		args->board[pos / args->size][pos % args->size] = try;
		if (valid(args, pos) == 42)
			return (1);
		else if (valid(args, pos) == 1 && pos < args->size * args->size - 1)
		{
			if (solve(args, pos + 1) == 1)
				return (1);
		}
	}
	if (pos == 0)
		return (0);
	args->board[pos / args->size][pos % args->size] = 0;
	return (0);
}