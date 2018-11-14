/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:21:31 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/25 17:21:35 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCHER_H
# define LAUNCHER_H

# include "flag_warpper.h"
# include "macros.h"
# include "parse_cli.h"

void	launch_fn_str(char *filename, t_flag_warpper *fw, t_hash_type type);
void	launch_p(t_flag_warpper *fw);
int		launch_s(t_flag_warpper *fw, char **argv, int i, int j);

#endif
