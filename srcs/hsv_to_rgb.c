/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:44:26 by svassal           #+#    #+#             */
/*   Updated: 2016/10/06 12:50:46 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define REGION	uc[0]
#define FPART	uc[1]
#define P		uc[2]
#define Q		uc[3]
#define T		uc[4]
#define R		0xFF00
#define G		0xFF
#define B		0x1

/*
** Convert HSV color to RGB color
*/

int		hsv_to_rgb(unsigned char h, unsigned char s, unsigned char v)
{
	unsigned char		uc[5];
	int					c;

	c = 0;
	if (s == 0)
		return (R * v + G * v + B * v);
	REGION = h / 43;
	FPART = (h - (REGION * 43)) * 6;
	P = (v * (255 - s)) >> 8;
	Q = (v * (255 - ((s * FPART) >> 8))) >> 8;
	T = (v * (255 - ((s * (255 - FPART)) >> 8))) >> 8;
	if (REGION == 0)
		return (R * v + G * T + B * P);
	if (REGION == 1)
		return (R * Q + G * v + B * P);
	if (REGION == 2)
		return (R * P + G * v + B * T);
	if (REGION == 3)
		return (R * P + G * Q + B * v);
	if (REGION == 4)
		return (R * T + G * P + B * v);
	return (R * v + G * P + B * Q);
}
