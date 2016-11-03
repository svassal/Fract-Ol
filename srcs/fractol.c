/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:44:16 by svassal           #+#    #+#             */
/*   Updated: 2016/10/06 12:54:39 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Exit program
*/

static int			exit_program(t_env *e)
{
	clean_env(e);
	exit(1);
}

/*
** Key Hook
** 8 = C
** 53 = ESC
** 69 = +
** 78 = -
** 83 = NUMPAD_1
** 84 = NUMPAD_2
** 85 = NUMPAD_3
** 86 = NUMPAD_4
** 87 = NUMPAD_5
** 88 = NUMPAD_6
** 89 = NUMPAD_7
** 91 = NUMPAD_8
** 92 = NUMPAD_9
*/

static int			key_h(int kc, void *p)
{
	if (kc == 8)
		color_mode((t_env *)p);
	if (kc == 53)
		exit_program((t_env *)p);
	if (kc == 69)
		k_z(kc, (t_env *)p);
	if (kc == 78)
		k_z(kc, (t_env *)p);
	if ((kc >= 83 && kc <= 89) || kc == 91 || kc == 92)
		move_fractal((t_env *)p, kc);
	exp_h(p);
	return (0);
}

/*
** Manage MLX events
*/

static void			mlx_event(t_env *env)
{
	mlx_hook(env->window, 4, 0, m_w_hook, (void *)env);
	mlx_hook(env->window, 6, 0, m_c_hook, (void *)env);
	mlx_key_hook(env->window, key_h, (void *)env);
	mlx_hook(env->window, 17, 0, exit_program, (void *)env);
	mlx_expose_hook(env->window, exp_h, (void *)env);
	mlx_loop(env->mlx);
}

int					main(int argc, char **argv)
{
	t_env	*e;

	if ((e = malloc(sizeof(t_env))) == 0)
		return (0);
	if (argc == 2)
		define_fractal(e, argv[1]);
	init_env(e);
	if (argc != 2)
	{
		clean_env(e);
		ft_putendl("Usage : fractol [fractal name]");
		ft_putendl("Fractal names : julia, mandelbrot, burningship");
		return (0);
	}
	if (e->type == NONE)
	{
		clean_env(e);
		ft_putendl("Bad Fractal Name !");
		ft_putendl("Fractal names : julia, mandelbrot, burningship");
		return (0);
	}
	draw_fractal(e);
	mlx_event(e);
	return (1);
}
