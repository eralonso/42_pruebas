/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:05:33 by eralonso          #+#    #+#             */
/*   Updated: 2023/06/21 16:07:06 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITS_H
# define BITS_H

# include	<unistd.h>

char	swap_bits(char octet);
char	reverse_byte(char octet);
void	print_reverse_bits(char octet);
void	print_bits(char octet);

#endif
