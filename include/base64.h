/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:54:23 by trecomps          #+#    #+#             */
/*   Updated: 2018/11/14 10:54:31 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

#include <string.h>
#include "base64_helpers.h"

char		*base64_e(char *message, size_t *output_len);
char		*base64_d(char *message, size_t *output_len);

#endif
