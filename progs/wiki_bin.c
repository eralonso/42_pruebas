/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wiki_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:04:21 by eralonso          #+#    #+#             */
/*   Updated: 2023/06/21 16:33:58 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	"bits.h"

#define F_DIC_BI_B	(char *)"dictionary_binary_byte.txt"

int	size_num(int num)
{
	long	n;
	int		size;

	n = num;
	if (num < 0)
		n = -num;
	size = 1;
	while (num > 9)
	{
		num /= 10;
		size++;
	}
	return (size);
}

void	putnbr(int num)
{
	int		size;
	int		aux;
	int		i;
	char	c;
	
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	size = size_num(num);
	while (size > 0)
	{
		i = 1;
		aux = num;
		while (i < size)
		{
			aux /= 10;
			i++;
		}
		c = (aux % 10) + '0';
		write(1, &c, 1);
		size--;
	}
}

int	main(void)
{
	int	fd;
	int	tmp_fd;
	int	num;
	int	nl;

	fd = open(F_DIC_BI_B, O_CREAT | O_TRUNC | O_RDWR, 0666);
	if (fd == -1)
	{
		dprintf(2, "Error creating a file: %s", F_DIC_BI_B);
		exit(1);
	}
	tmp_fd = dup(1);
	dup2(fd, 1);
	num = -129;
	nl = 1;
	while (++num < 128)
	{
		putnbr(num);
		write(1, " : ", 3);
		print_bits(num);
		if (num + 1 < 128 && nl > 0 && nl % 5 == 0)
			write(1, "\n\n", 2);
		else if (num + 1 < 128)
			write(1, "  |  ", 5);
		nl++;
	}
	write(1, "\n", 1);
	dup2(tmp_fd, 1);
	close(tmp_fd);
	printf("Finished\n");
}