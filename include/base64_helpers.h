/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_helpers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:17:00 by trecomps          #+#    #+#             */
/*   Updated: 2018/11/16 16:17:01 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_HELPERS_H
# define BASE64_HELPERS_H

#include "libft.h"
#include "stdio.h"

uint32_t	get_24bits(char *message);
uint32_t	get_4_char(char *encoded, size_t len);
void		encode_bits(uint32_t message, char *encoded, size_t message_len);
void		decode_bit(uint32_t bits_message, char *decoded, size_t e_len);

#endif
