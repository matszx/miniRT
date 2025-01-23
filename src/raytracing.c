/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:50:54 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/23 10:39:42 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

double	sphere_hit(t_ray ray, t_point center, double r)
{
	t_vec	oc;
	double	a;
	double	h;
	double	c;
	double	discriminant;

	oc = sub_v(center, ray.origin);
	a = len_v_squared(ray.dir);
	h = dot(ray.dir, oc);
	c = len_v_squared(oc) - r * r;
	discriminant = h * h - a * c;
	if (discriminant < 0)
		return (-1);
	return ((h - sqrt(discriminant)) / a);
}
