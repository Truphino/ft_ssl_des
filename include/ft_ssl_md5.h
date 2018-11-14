/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 11:20:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/19 11:44:06 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H

# include "externals_headers.h"
# include "libft.h"
# include "bitswap.h"
# include "hash_tools.h"
# include "flag_warpper.h"
# include "helpers.h"
# include "macros.h"
# include "base64.h"

typedef struct		s_md
{
	uint8_t			*str;
	uint64_t		md_lenght;
}					t_md;

void				calc_fg_i_16(uint32_t i, uint32_t v[4], uint32_t val[2]);
void				calc_fg_i_32(uint32_t i, uint32_t v[4], uint32_t val[2]);
void				calc_fg_i_48(uint32_t i, uint32_t v[4], uint32_t val[2]);
void				calc_fg_i_64(uint32_t i, uint32_t v[4], uint32_t val[2]);
char				*md5(char *message);
char				*sha256(char *message);
t_md				padding_md5_sha2(char const *message, int is_be);
char				*h_values_hexstr(uint32_t *v, uint32_t size, int is_be);
char				*hash_file(t_flag_warpper fw, char *filename);
char				*file_to_string(int fd);

#endif
