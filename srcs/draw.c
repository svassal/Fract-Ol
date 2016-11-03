/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:44:01 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 13:44:02 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Draw the fractal contained in "type" data from env
*/

void		draw_fractal(t_env *e)
{
	mlx_clear_window(e->mlx, e->window);
	clear_image(e);
	if (e->type == JULIA)
		julia(e);
	else if (e->type == MANDELBROT)
		mandelbrot(e);
	else if (e->type == BURNINGSHIP)
		burningship(e);
	mlx_put_image_to_window(e->mlx, e->window, e->image->image, 0, 0);
}

/*
** Clear image content by filling each pixel with a grey color
*/

void		clear_image(t_env *e)
{
	int		max;
	int		index;

	max = (e->w_height * e->w_width);
	index = -1;
	while (++index < max)
		*(e->image->beg + index) = 0x55333333;
}

/*
** Write a pixel in the image
*/

void		write_pixel_image(t_env *e, int x, int y, int color)
{
	int		pos;

	pos = x + (y * e->w_width);
	*(e->image->beg + pos) = color;
}
