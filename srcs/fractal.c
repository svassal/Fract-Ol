/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:44:08 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 13:44:09 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Remove the current fractal data and get the next one in list
*/

static void		rm_fra(t_env *e)
{
	t_list *l;

	if (e->fractal->next != 0)
	{
		l = e->fractal->next;
		free(e->fractal->content);
		free(e->fractal);
		e->fractal = l;
	}
}

/*
** Add a fractal with data passed as parameters
*/

t_fract			*add_fract(float x[2], float y[2], float i_m, float z)
{
	t_fract		*f;

	if ((f = malloc(sizeof(t_fract))) == 0)
		return (0);
	f->x_min = x[0];
	f->x_max = x[1];
	f->y_min = y[0];
	f->y_max = y[1];
	f->iter = i_m;
	f->zoom = z;
	return (f);
}

/*
** Return the current fractal element
*/

t_fract			*cur_fract(t_env *e)
{
	return (((t_fract *)e->fractal->content));
}

/*
** Manage zoom on the fractal to the positions given as parameters
*/

void			zoom_fractale(t_env *e, int s, int x, int y)
{
	float	x_m[2];
	float	y_m[2];
	float	p[6];

	if (s == 0)
		rm_fra(e);
	else
	{
		x_m[0] = cur_fract(e)->x_min;
		x_m[1] = cur_fract(e)->x_max;
		y_m[0] = cur_fract(e)->y_min;
		y_m[1] = cur_fract(e)->y_max;
		p[0] = ((float)x / (float)e->w_width);
		p[1] = 1.0 - p[0];
		p[2] = ((float)y / (float)e->w_height);
		p[3] = 1.0 - p[0];
		p[4] = cur_fract(e)->zoom * 1.01;
		x_m[0] -= x_m[0] * (p[0] * 0.01);
		x_m[1] -= x_m[1] * (p[1] * 0.01);
		y_m[0] -= y_m[0] * (p[2] * 0.01);
		y_m[1] -= y_m[1] * (p[3] * 0.01);
		p[5] = cur_fract(e)->iter * 1.01;
		ft_lstadd(&e->fractal, ft_lstnew(add_fract(x_m, y_m, p[5], p[4]),
			sizeof(t_fract)));
	}
}
