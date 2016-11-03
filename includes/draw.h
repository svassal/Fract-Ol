/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:59:38 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 13:59:38 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "fractol.h"

void		clear_image(t_env *e);
void		write_pixel_image(t_env *e, int x, int y, int color);
void		draw_fractal(t_env *e);

#endif
