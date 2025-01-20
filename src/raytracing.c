/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:50:54 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/20 11:30:18 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

double	sphere_hit(t_ray ray, t_point center, double r)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = sub_v(center, ray.origin);
	a = scalar(ray.dir, ray.dir);
	b = scalar(ray.dir, oc) * -2.0;
	c = scalar(oc, oc) - r * r;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	return ((-sqrt(discriminant) - b) / (a * 2.0));
}
