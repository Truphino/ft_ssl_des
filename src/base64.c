/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:08:25 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/26 15:08:26 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include "base64_helpers.h"

char			*base64_e(char *message, size_t *output_len)
{
	size_t		message_len;
	size_t		i;
	uint32_t	bits_message;
	char		*encoded;

	i = 0;
	message_len = ft_strlen(message);
	*output_len = ((message_len - 1) / 3) * 4 + 4;
	encoded = (char *)ft_memalloc(*output_len + 1);
	while (i < *output_len / 4)
	{
		bits_message = get_24bits(message + i * 3);
		encode_bits(bits_message, encoded + i * 4, message_len);
		message_len -= 3;
		i++;
	}
	return (encoded);
}

char		*base64_d(char *encoded, size_t *output_len)
{
	size_t		encoded_len;
	size_t		i;
	uint32_t	bits_message;
	char		*decoded;

	i = 0;
	encoded_len = ft_strlen(encoded);
	while (encoded[encoded_len - 1] == '=')
		encoded_len--;
	*output_len = ((encoded_len - 1) / 4) * 3 + 3;
	//printf("Encoded len :%lu\tDecoded len :%lu\n", encoded_len, *output_len);
	decoded = (char *)ft_memalloc(*output_len + 1);
	while (i < *output_len / 3)
	{
		bits_message = get_4_char(encoded + i * 4, encoded_len);
		decode_bit(bits_message, decoded + i * 3, encoded_len);
		encoded_len -= 4;
		i++;
	}
	return (decoded);
}
