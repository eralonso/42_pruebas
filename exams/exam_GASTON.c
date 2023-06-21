/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_GASTON.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:57:18 by eralonso          #+#    #+#             */
/*   Updated: 2023/06/13 16:10:20 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	search_and_replace(char *str, char search, char replace)
int	main(int ac, char **av)
{
	int	i;
	
	i = 0;
	if (ac == 4)
	{
		while (str[i])
		{
			if (str[i] == search)
				str[i] = replace;
			i++;
		}
		write(1, str, i);
	}
	write(1, "\n", 1);
}