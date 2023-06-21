/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:52:41 by eralonso          #+#    #+#             */
/*   Updated: 2023/06/18 15:54:50 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<unistd.h>

int	main(void)
{
	int	fd[2];

	fd[0] = 0;
	fd[1] = 1;
	printf("dup2(fd[0], 0) == %i\n", dup2(fd[0], 0));
	printf("dup2(fd[1], 1) == %i\n", dup2(fd[1], 1));
	printf("dup2(fd[0], 0) == %i\n", dup2(fd[0], 0));
	printf("dup2(fd[1], 1) == %i\n", dup2(fd[1], 1));
	printf("dup2(fd[0], 0) == %i\n", dup2(fd[0], 0));
	printf("dup2(fd[1], 1) == %i\n", dup2(fd[1], 1));
	return (0);
}