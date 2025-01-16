/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:22:26 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/16 18:39:49 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <math.h>

typedef struct s_vec3
{
	double	e[3];
}	t_vec3;

typedef struct s_ray
{
	double	origin[3];
	t_vec3	dir;
}	t_ray;

t_vec3	v_init(double *x, double *y, double *z);
t_vec3	v_sum(t_vec3 *v1, t_vec3 *v2);
t_vec3	v_mul(t_vec3 *v1, t_vec3 *v2);
double	v_dot(t_vec3 *v1, t_vec3 *v2);
double	v_len(t_vec3 *v);
