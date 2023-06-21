/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:49:52 by eralonso          #+#    #+#             */
/*   Updated: 2023/06/08 12:54:00 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdio.h>
#include	<fcntl.h>

int	main(void)
{
	int	fd;
	int	tmp_fd;

	//printf("isatty 1: %i\n", isatty(1));
	//write(1, "\n", 1);
	//printf("\n");
	fd = open("out", O_CREAT | O_RDWR, 0777);
	tmp_fd = dup(1);
	dup2(fd, 1);
	write(1, "Hola", 4);
	//printf("isatty 1: %i\n", isatty(1));
	//printf("Hola\n");
	dup2(tmp_fd, 1);
	//printf("isatty fd: %i\n", isatty(fd));
	//printf("isatty 1: %i\n", isatty(1));
	return (0);
}
