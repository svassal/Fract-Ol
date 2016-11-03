/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:44:32 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 13:44:33 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define X_MIN	((t_fract *)e->fractal->content)->x_min
#define X_MAX	((t_fract *)e->fractal->content)->x_max
#define Y_MIN	((t_fract *)e->fractal->content)->y_min
#define Y_MAX	((t_fract *)e->fractal->content)->y_max
#define IMAGE_X	f[0]
#define IMAGE_Y f[1]
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
** First initialization of julia fractal
*/

static void		julia_init(t_env *e)
{
	float	x[2];
	float	y[2];
	float	i;

	i = 150.0;
	x[0] = BX0_J;
	x[1] = BX1_J;
	y[0] = BY0_J;
	y[1] = BY1_J;
	ft_lstadd(&e->fractal, ft_lstnew(add_fract(x, y, i, 300.0),
		sizeof(t_fract)));
}

/*
** Initialize some numbers for the julia fractal
*/

static void		nbr_init(t_env *e, float f[7], int n[4], int t)
{
	if (t == 1)
	{
		I_M = cur_fract(e)->iter;
		IMAGE_X = (X_MAX - X_MIN) * cur_fract(e)->zoom;
		X = -1;
	}
	if (t == 2)
	{
		C_R = ((float)((float)e->mouse_x / (e->w_width))) * 2.4 - 1.2;
		C_I = ((float)((float)e->mouse_y / (e->w_height))) * 2 - 1;
		Z_R = X / cur_fract(e)->zoom + X_MIN;
		Z_I = Y / cur_fract(e)->zoom + Y_MIN;
		I = -1;
	}
}

/*
** Draw julia fractal to the image
*/

void			julia(t_env *e)
{
	float		f[7];
	int			n[4];

	if (e->fractal == 0)
		julia_init(e);
	nbr_init(e, f, n, 1);
	while (++X < e->w_width)
	{
		Y = -1;
		while (++Y < e->w_height)
		{
			nbr_init(e, f, n, 2);
			while (Z_R * Z_R + Z_I * Z_I < 4 && ++I < I_M)
			{
				TMP = Z_R;
				Z_R = Z_R * Z_R - Z_I * Z_I + C_R;
				Z_I = 2 * Z_I * TMP + C_I;
			}
			write_pixel_image(e, X, Y, color(e, I, I_M));
		}
	}
}
