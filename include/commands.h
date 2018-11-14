/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:03:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/25 17:03:34 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "flag_warpper.h"

void				print_command_list(void);
void				parse_command_name(char *cmd_name, t_flag_warpper *fw);
void				print_usage(t_flag_warpper fw);

#endif
