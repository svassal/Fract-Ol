/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:00:10 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 14:00:11 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H
# define BX0_M	-2.1
# define BX1_M	0.6
# define BY0_M	-1.2
# define BY1_M	1.2
# include "fractol.h"

void		mandelbrot(t_env *e);

#endif
