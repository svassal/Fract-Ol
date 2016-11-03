/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:00:20 by svassal           #+#    #+#             */
/*   Updated: 2016/09/28 14:00:20 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H
# include "fractol.h"

int			exp_h(void *p);
int			m_c_hook(int x, int y, void *p);
int			m_w_hook(int pos, int i1, int i2, void *p);
int			k_z(int kc, t_env *e);

#endif
