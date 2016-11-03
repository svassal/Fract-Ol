/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:59:50 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 13:59:51 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "fractol.h"

t_fract			*cur_fract(t_env *e);
void			zoom_fractale(t_env *e, int s, int x, int y);
t_fract			*add_fract(float x[2], float y[2], float i_m, float z);

#endif
