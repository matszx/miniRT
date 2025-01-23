/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:33:11 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/23 10:53:24 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_vec	vec(double x, double y, double z)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec	sub_n(t_vec v, double n)
{
	return (vec(v.x - n, v.y - n, v.z - n));
}

t_vec	sum_n(t_vec v, double n)
{
	return (vec(v.x + n, v.y + n, v.z + n));
}

t_vec	div_n(t_vec v, double n)
{
	return (vec(v.x / n, v.y / n, v.z / n));
}

t_vec	mul_n(t_vec v, double n)
{
	return (vec(v.x * n, v.y * n, v.z * n));
}

t_vec	sub_v(t_vec v1, t_vec v2)
{
	return (vec(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vec	sum_v(t_vec v1, t_vec v2)
{
	return (vec(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vec	div_v(t_vec v1, t_vec v2)
{
	return (vec(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z));
}

t_vec	mul_v(t_vec v1, t_vec v2)
{
	return (vec(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z));
}

double	dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double	len_v(t_vec v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double	len_v_squared(t_vec v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vec	unit_v(t_vec v)
{
	return (div_n(v, len_v(v)));
}

t_ray	ray(t_vec origin, t_vec dir)
{
	t_ray	r;

	r.origin = origin;
	r.dir = dir;
	return (r);
}

t_point	dst(t_ray r, double t)
{
	return (sum_v(r.origin, mul_n(r.dir, t)));
}
