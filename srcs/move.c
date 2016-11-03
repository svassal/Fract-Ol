/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:44:48 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 13:44:49 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Save values for futur utilisation
*/

static void		nbr_init(t_fract *t, float f[6])
{
	f[0] = t->x_min;
	f[1] = t->x_max;
	f[2] = t->y_min;
	f[3] = t->y_max;
	f[4] = (f[1] - f[0]) * 0.01;
	f[5] = (f[3] - f[2]) * 0.01;
}

/*
** Use to move julia fractal
*/

static void		move_julia(t_fract *t, int kc)
{
	float	f[6];

	nbr_init(t, f);
	if (kc == 83 || kc == 84 || kc == 85)
	{
		t->y_max = (f[3] + f[5] >= BY1_J) ? (BY1_J) : (f[3] + f[5]);
		t->y_min = (f[3] + f[5] >= BY1_J) ? (f[2]) : (f[2] + f[5]);
	}
	if (kc == 89 || kc == 91 || kc == 92)
	{
		t->y_min = (f[2] - f[5] <= BY0_J) ? (BY0_J) : (f[2] - f[5]);
		t->y_max = (f[2] - f[5] <= BY0_J) ? (f[3]) : (f[3] - f[5]);
	}
	if (kc == 83 || kc == 86 || kc == 89)
	{
		t->x_min = (f[0] - f[4] <= BX0_J) ? (BX0_J) : (f[0] - f[4]);
		t->x_max = (f[0] - f[4] <= BX0_J) ? (f[1]) : (f[1] - f[4]);
	}
	if (kc == 85 || kc == 88 || kc == 92)
	{
		t->x_max = (f[1] + f[4] >= BX1_J) ? (BX1_J) : (f[1] + f[4]);
		t->x_min = (f[1] + f[4] >= BX1_J) ? (f[0]) : (f[0] + f[4]);
	}
}

/*
** Used to move mandelbrot fractal
*/

static void		move_mandelbrot(t_fract *t, int kc)
{
	float	f[6];

	nbr_init(t, f);
	if (kc == 83 || kc == 84 || kc == 85)
	{
		t->y_max = (f[3] + f[5] >= BY1_M) ? (BY1_M) : (f[3] + f[5]);
		t->y_min = (f[3] + f[5] >= BY1_M) ? (f[2]) : (f[2] + f[5]);
	}
	if (kc == 89 || kc == 91 || kc == 92)
	{
		t->y_min = (f[2] - f[5] <= BY0_M) ? (BY0_M) : (f[2] - f[5]);
		t->y_max = (f[2] - f[5] <= BY0_M) ? (f[3]) : (f[3] - f[5]);
	}
	if (kc == 83 || kc == 86 || kc == 89)
	{
		t->x_min = (f[0] - f[4] <= BX0_M) ? (BX0_M) : (f[0] - f[4]);
		t->x_max = (f[0] - f[4] <= BX0_M) ? (f[1]) : (f[1] - f[4]);
	}
	if (kc == 85 || kc == 88 || kc == 92)
	{
		t->x_max = (f[1] + f[4] >= BX1_M) ? (BX1_M) : (f[1] + f[4]);
		t->x_min = (f[1] + f[4] >= BX1_M) ? (f[0]) : (f[0] + f[4]);
	}
}

/*
** Use to move burningship fractal
*/

void			move_burningship(t_fract *t, int kc)
{
	float		f[6];

	nbr_init(t, f);
	if (kc == 83 || kc == 84 || kc == 85)
	{
		t->y_max = (f[3] + f[5] >= BY1_B) ? (BY1_B) : (f[3] + f[5]);
		t->y_min = (f[3] + f[5] >= BY1_B) ? (f[2]) : (f[2] + f[5]);
	}
	if (kc == 89 || kc == 91 || kc == 92)
	{
		t->y_min = (f[2] - f[5] <= BY0_B) ? (BY0_B) : (f[2] - f[5]);
		t->y_max = (f[2] - f[5] <= BY0_B) ? (f[3]) : (f[3] - f[5]);
	}
	if (kc == 83 || kc == 86 || kc == 89)
	{
		t->x_min = (f[0] - f[4] <= BX0_B) ? (BX0_B) : (f[0] - f[4]);
		t->x_max = (f[0] - f[4] <= BX0_B) ? (f[1]) : (f[1] - f[4]);
	}
	if (kc == 85 || kc == 88 || kc == 92)
	{
		t->x_max = (f[1] + f[4] >= BX1_B) ? (BX1_B) : (f[1] + f[4]);
		t->x_min = (f[1] + f[4] >= BX1_B) ? (f[0]) : (f[0] + f[4]);
	}
}

/*
** Move the fractal
*/

void			move_fractal(t_env *e, int kc)
{
	if (e->type == JULIA)
		move_julia(cur_fract(e), kc);
	else if (e->type == MANDELBROT)
		move_mandelbrot(cur_fract(e), kc);
	else if (e->type == BURNINGSHIP)
		move_burningship(cur_fract(e), kc);
}
