/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:43:36 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/16 18:43:40 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/render.h"

t_vec3	v_init(double *x, double *y, double *z)
{
	t_vec3	v;

	v.e[0] = *x;
	v.e[1] = *y;
	v.e[2] = *z;
	return (v);
}

t_vec3	v_sum(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	res;

	res.e[0] = v1->e[0] + v2->e[0];
	res.e[1] = v1->e[1] + v2->e[1];
	res.e[2] = v1->e[2] + v2->e[2];
	return (res);
}

t_vec3	v_mul(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	res;

	res.e[0] = v1->e[0] * v2->e[0];
	res.e[1] = v1->e[1] * v2->e[1];
	res.e[2] = v1->e[2] * v2->e[2];
	return (res);
}

double	v_dot(t_vec3 *v1, t_vec3 *v2)
{
	return (v1->e[0] * v2->e[0] + v1->e[1] * v2->e[1] + v1->e[2] * v2->e[2]);
}

double	v_len(t_vec3 *v)
{
	return (sqrt(v->e[0] * v->e[0] + v->e[1] * v->e[1] + v->e[2] * v->e[2]));
}
