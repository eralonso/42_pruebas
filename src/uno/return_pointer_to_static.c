/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_pointer_to_static.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:20:44 by eralonso          #+#    #+#             */
/*   Updated: 2023/05/21 16:12:39 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<prueba.h>

// int	arr(int n)[2]
// {
// 	int new[2];

// 	new[0] = n + 1;
// 	new[1] = n + 2;
// 	return (new);
// }

int	(*pt(int n))[2]
{
	int	(*new)[2];
	int	i;

	new = calloc(n, sizeof(int [2]));
	i = -1;
	while (++i < n)
	{
		new[i][0] = (i + 1);
		new[i][1] = -(i + 1);
	}
	return (new);
}

// int	main(void)
char	*principio(void)
{
	int	(*ret)[2];
	// int	n_ret[2];
	int	i;
	int	n;

	n = 5;
	ret = pt(n);
	// n_ret = arr(n);
	i = -1;
	while (++i < n)
		printf("ret[%i][0]: %i && ret[%i][1]: %i\n", i, ret[i][0], i, ret[i][1]);
	return (0);
}
