/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:59:43 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 13:59:44 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "fractol.h"

void		init_env(t_env *e);
void		define_fractal(t_env *e, char *str);
int			m_c_hook(int x, int y, void *p);

#endif
