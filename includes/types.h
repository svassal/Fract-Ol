/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:00:29 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 14:00:30 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef struct		s_fract
{
	float			x_min;
	float			x_max;
	float			y_min;
	float			y_max;
	float			iter;
	float			zoom;
}					t_fract;
typedef enum		e_color
{
	MINIMAL, PSYCHE
}					t_color;
typedef enum		e_type
{
	NONE, JULIA, MANDELBROT, BURNINGSHIP
}					t_type;
typedef struct		s_image
{
	void			*image;
	int				*beg;
	int				bpp;
	int				size_l;
	int				endian;
}					t_image;
typedef	struct		s_env
{
	void			*mlx;
	void			*window;
	int				w_width;
	int				w_height;
	int				mouse_x;
	int				mouse_y;
	t_type			type;
	t_image			*image;
	t_list			*fractal;
	t_color			color;
}					t_env;

#endif
