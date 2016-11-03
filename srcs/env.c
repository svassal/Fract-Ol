/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:44:05 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 13:44:06 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Save fractal type in the env according to the string passed as parameter
*/

void		define_fractal(t_env *e, char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		e->type = MANDELBROT;
	else if (ft_strcmp(str, "julia") == 0)
		e->type = JULIA;
	else if (ft_strcmp(str, "burningship") == 0)
		e->type = BURNINGSHIP;
	else
		e->type = NONE;
}

/*
** Gives the window definition according to the chosen fractal
*/

static void	window_def(t_env *e)
{
	e->w_width = 300;
	e->w_height = 300;
	if (e->type == MANDELBROT)
	{
		e->w_width *= (BX1_M - BX0_M);
		e->w_height *= (BY1_M - BY0_M);
	}
	else if (e->type == JULIA)
	{
		e->w_width *= (BX1_J - BX0_J);
		e->w_height *= (BY1_J - BY0_J);
	}
	else if (e->type == BURNINGSHIP)
	{
		e->w_width *= (BX1_B - BX0_B);
		e->w_height *= (BY1_B - BY0_B);
	}
}

/*
** Initialize fractol env
*/

void		init_env(t_env *e)
{
	e->mlx = mlx_init();
	window_def(e);
	e->mouse_x = e->w_width / 2;
	e->mouse_y = e->w_height / 4 - e->w_height / 8;
	e->window = mlx_new_window(e->mlx, e->w_width, e->w_height, "Fract'Ol");
	e->color = MINIMAL;
	if ((e->image = malloc(sizeof(t_image))) != 0)
	{
		e->image->image = mlx_new_image(e->mlx, e->w_width, e->w_height);
		e->image->beg = (int *)mlx_get_data_addr(e->image->image,
		&(e->image->bpp), &(e->image->size_l), &(e->image->endian));
	}
	else
		e->image = 0;
	e->fractal = 0;
}
