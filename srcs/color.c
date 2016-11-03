/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:43:56 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 13:43:58 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Switch the color mode
*/

void		color_mode(t_env *e)
{
	if (e->color == MINIMAL)
		e->color = PSYCHE;
	else
		e->color = MINIMAL;
}

/*
** Return a color (minimal)
*/

static int	minimal_color_set(int i, int i_m)
{
	if (i == i_m)
		return (0x000000);
	return (i * 255 / i_m);
}

/*
** Calcul color of the point
*/

int			color(t_env *e, int i, int i_m)
{
	if (e->color == MINIMAL)
		return (minimal_color_set(i, i_m));
	return (hsv_to_rgb(i % 256, 255, 255 * (i < i_m)));
}
