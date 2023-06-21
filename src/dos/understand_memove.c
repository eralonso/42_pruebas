/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   understand_memove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:56:29 by eralonso          #+#    #+#             */
/*   Updated: 2023/05/21 16:13:35 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<prueba.h>

// int	main(void)
char	*principio(void)
{
	char	*var1;
	char	*var2;

	var1 = "hola";
	var2 = "adiosss";
	printf("var1: %p && var2: %p\n", var1, var2);
	printf("difference: %ld\n", var2 - var1);
	return (0);
}