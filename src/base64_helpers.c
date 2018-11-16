/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_helps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:14:34 by trecomps          #+#    #+#             */
/*   Updated: 2018/11/16 16:14:35 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

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

static uint8_t			search_tab_value(char encoded)
{
	uint8_t		i;

	i = 0;
	while (g_base64_tab[i])
	{
		if (g_base64_tab[i] == encoded)
			return (i);
		i++;
	}
	return (255);
}

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

uint32_t		get_4_char(char *encoded, size_t len)
{
	uint32_t	ret;
	uint8_t		append;
	size_t		i;

	i = 0;
	ret = 0;
	while (i < 4 && i < len)
	{
		append = search_tab_value(encoded[i]);
		ret = (ret << 6) | append;
		i++;
	}
	if (len == 3)
		ret = ret >> 2;
	if (len == 2)
		ret = ret >> 4;
	return (ret);
}


void		decode_bit(uint32_t bits_message, char *decoded, size_t encoded_len)
{
	size_t	count;

	count = 0;
	if (encoded_len >= 4)
	{
		*(decoded) = (bits_message & (0xFF << 16)) >> 16;
		count++;
	}
	if (encoded_len >= 3)
	{
		*(decoded + count) = (bits_message & (0xFF << 8)) >> 8;
		count++;
	}
	if (encoded_len >= 2)
	{
		*(decoded + count) = (bits_message & (0xFF << 0)) >> 0;
	}
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
