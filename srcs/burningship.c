/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:43:52 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 13:43:54 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define X_MIN	((t_fract *)e->fractal->content)->x_min
#define X_MAX	((t_fract *)e->fractal->content)->x_max
#define Y_MIN	((t_fract *)e->fractal->content)->y_min
#define Y_MAX	((t_fract *)e->fractal->content)->y_max
#define IMAGE_X	f[0]
#define IMAGE_Y	f[1]
#define X		n[0]
#define Y		n[1]
#define I		n[2]
#define I_M		n[3]
#define C_R		f[2]
#define C_I		f[3]
#define Z_R		f[4]
#define Z_I		f[5]
#define TMP		f[6]

/*
** First initialization of burningship fractal
*/

static void		burningship_init(t_env *e)
{
	float	x[2];
	float	y[2];
	int		i;

	i = 50.0;
	x[0] = BX0_B;
	x[1] = BX1_B;
	y[0] = BY0_B;
	y[1] = BY1_B;
	ft_lstadd(&e->fractal, ft_lstnew(add_fract(x, y, i, 300.0),
		sizeof(t_fract)));
}

/*
** Some numbers initialization for burningship fractal
*/

static void		nbr_init(t_env *e, float f[7], int n[4], int t)
{
	if (t == 1)
	{
		I_M = cur_fract(e)->iter;
		IMAGE_X = (X_MAX - X_MIN) * cur_fract(e)->zoom;
		IMAGE_Y = (Y_MAX - Y_MIN) * cur_fract(e)->zoom;
		X = -1;
	}
	if (t == 2)
	{
		C_R = (X_MIN + (X_MAX - X_MIN) / 2) + 2.0 * (X_MAX - X_MIN) *
			((float)X / e->w_width - 0.5);
		C_I = (Y_MIN + (Y_MAX - Y_MIN) / 2) + 2.0 * (Y_MAX - Y_MIN) *
			((float)Y / e->w_height - 0.5);
		Z_R = 0.0;
		Z_I = 0.0;
		I = -1;
	}
}

/*
** Draw burningship fractal
*/

void			burningship(t_env *e)
{
	float	f[7];
	int		n[4];

	if (e->fractal == 0)
		burningship_init(e);
	nbr_init(e, f, n, 1);
	while (++X < e->w_width)
	{
		Y = -1;
		while (++Y < e->w_height)
		{
			nbr_init(e, f, n, 2);
			while (Z_R * Z_R + Z_I * Z_I < 10 && ++I < I_M)
			{
				TMP = Z_I;
				Z_I = (Z_R * Z_I < 0) ? (2 * -(Z_R * Z_I) - C_I) :
					(2 * (Z_R * Z_I) - C_I);
				Z_R = Z_R * Z_R - TMP * TMP - C_R;
			}
			write_pixel_image(e, X, Y, color(e, I, I_M));
		}
	}
}
