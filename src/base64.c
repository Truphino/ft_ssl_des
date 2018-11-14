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

static char		g_base64_tab[] =
{
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/', '\0'
};

/*

000111 010000   =      =
0001101 0000    =      =

000111 000111 000100   =
00011100 01110001 00   =

000111 000111 000111 000111
00011100 01110001 11000111

*/

uint32_t		get_24bits(char *message)
{
	uint32_t	ret;
	size_t		len;

	ret = 0;
	len = ft_strlen(message);
	if (len)
		ret = *message;
	if (len > 1)
		ret = (ret << 8) | (*(message + 1));
	if (len > 2)
		ret = (ret << 8) | (*(message + 2));
	return (ret);
}

void			encode_bits(uint32_t message, char *encoded, size_t message_len)
{
	uint32_t	mask;
	size_t		i;

	i = 0;
	mask = 0x3F << 18;
	if (message_len == 1)
		message = message << 4 << 12;
	else if (message_len == 2)
		message = message << 2 << 6;
	while (i < 4)
	{
		if (message_len < 3 && i > message_len)
			encoded[i] = '=';
		else
			encoded[i] = g_base64_tab[(message & mask) >> (18 - i * 6)];
		mask = mask >> 6;
		i++;
	}
}

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
	*output_len = (encoded_len / 4) * 3 + ((encoded_len % 4) - 1);
	decoded = (char *)ft_memalloc(*output_len + 1);
}
