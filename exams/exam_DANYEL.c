/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_DANYEL.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:17:37 by eralonso          #+#    #+#             */
/*   Updated: 2023/06/13 16:37:58 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>

char	swap_bits(char octet)
{
	return (octet << 4 | octet >> 4);
}

char	reverse_byte(char octet)
{
	char byte;
	int	i;

	i = 0;
	byte = 0;
	while (i < 8)
	{
		byte = (byte << 1) | ((octet >> i) & 1);
		i++;
	}
	return (byte);
}

void	print_reverse_bits(char octet)
{
	int		i;
	char	bit;

	i = 0;
	while (i < 8)
	{
		bit = (octet >> i) & 1;
		bit += '0';
		write(1, &bit, 1);
		i++;
	}
}

void	print_bits(char octet)
{
	int		i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (octet >> i) & 1;
		bit += '0';
		write(1, &bit, 1);
		i--;
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	print_bits(atoi(av[1]));
	return (0);
}