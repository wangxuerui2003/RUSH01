/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:27:52 by wxuerui           #+#    #+#             */
/*   Updated: 2023/02/20 14:59:17 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr < 0)
	{
		if (nbr == -2147483648)
			write(STDOUT_FILENO, "-2147483648", 11);
		else
			write(STDOUT_FILENO, "-", 1);
		nbr *= -1;
	}
	if (nbr / 10 != 0)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(STDOUT_FILENO, &c, 1);
}

int	error_msg(char *s)
{
	int	i;

	i = -1;
	while (s[++i] != 0)
		write(STDERR_FILENO, s + i, 1);
	return (i + 1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
