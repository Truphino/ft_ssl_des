/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:54:01 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/24 11:54:03 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

void	free_if(void **ptr);
void	free_null_terminated_tab(void **ptr);
char	*ft_strtoupper(const char *str);
char	*exit_ptr(char *null);

#endif
