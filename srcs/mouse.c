/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:44:45 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 13:44:45 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Expose Hook
*/

int			exp_h(void *p)
{
	draw_fractal((t_env *)p);
	return (0);
}

/*
** Get mouse pos on the window
*/

int			m_c_hook(int x, int y, void *p)
{
	if (x >= 0 && x < ((t_env *)p)->w_width && y >= 0 &&
		x < ((t_env *)p)->w_height)
	{
		((t_env *)p)->mouse_x = x;
		((t_env *)p)->mouse_y = y;
		exp_h((t_env *)p);
	}
	return (0);
}

/*
** Get mouse wheel change
*/

int			m_w_hook(int pos, int x, int y, void *p)
{
	if ((pos == 5 || pos == 4))
	{
		if (pos == 5)
			zoom_fractale((t_env *)p, 1, x, y);
		else if (pos == 4)
			zoom_fractale((t_env *)p, 0, 0, 0);
		exp_h(p);
	}
	return (1);
}

/*
** Keyboard zoom
*/

int			k_z(int kc, t_env *e)
{
	if (kc == 69)
	{
		mlx_hook(e->window, 6, 0, m_c_hook, (void *)e);
		zoom_fractale(e, 1, e->mouse_x, e->mouse_y);
	}
	if (kc == 78)
		zoom_fractale(e, 0, 0, 0);
	return (0);
}
