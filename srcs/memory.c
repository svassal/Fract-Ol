/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:44:41 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 13:44:41 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Clean the memory allocated to the "fractal list"
*/

void		clean_lst(t_list **l)
{
	t_list	*tmp;

	while (*l != 0)
	{
		tmp = *l;
		*l = (*l)->next;
		free(tmp->content);
		free(tmp);
	}
	*l = 0;
}

/*
** Clean the memory allocated to the env
*/

void		clean_env(t_env *e)
{
	if (e->window != 0)
		mlx_destroy_window(e->mlx, e->window);
	e->window = 0;
	if (e->image != 0)
	{
		mlx_destroy_image(e->mlx, e->image->image);
		free(e->image);
	}
	clean_lst(&e->fractal);
	if (e->mlx != 0)
		free(e->mlx);
	e->mlx = 0;
	if (e != 0)
		free(e);
	e = 0;
}
