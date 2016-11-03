/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:00:04 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 14:00:05 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JULIA_H
# define JULIA_H
# define BX0_J	-1
# define BX1_J	1
# define BY0_J	-1.2
# define BY1_J	1.2
# include "fractol.h"

void		julia(t_env *e);

#endif
