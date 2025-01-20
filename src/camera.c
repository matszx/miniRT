/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:45:25 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/20 11:29:30 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

void	camera_init(t_camera *c)
{
	c->window_height = HEIGHT;
	c->window_width = WIDTH;
	c->aspect_ratio = c->window_width / c->window_height;
	c->viewport_height = 2.0;
	c->viewport_width = c->viewport_height * c->aspect_ratio;
	c->focal_length = 1.0;
	c->center = vec(0.0, 0.0, 0.0);
	c->viewport_v = vec(0.0, -(c->viewport_height), 0.0);
	c->viewport_u = vec(c->viewport_width, 0.0, 0.0);
	c->delta_v = div_n(c->viewport_v, c->window_height);
	c->delta_u = div_n(c->viewport_u, c->window_width);
	c->viewport_ulp = sub_v(sub_v(sub_v(c->center, div_n(c->viewport_v, 2)), div_n(c->viewport_u, 2)), vec(0.0, 0.0, c->focal_length));
	c->pixel_zero = sum_v(c->viewport_ulp, mul_n(sum_v(c->delta_v, c->delta_u), 0.5));
}

t_colour	ray_colour(t_ray r)
{
	double	t;
	t_vec	n;
	double	a;

	t = sphere_hit(r, vec(0, 0, -1), 0.5);
	if (t > 0.0)
	{
		n = unit_v(sub_v(at(r, t), vec(0, 0, -1)));
		return (mul_n(vec(n.x + 1, n.y + 1, n.z + 1), 0.5));
	}
	a = (div_n(r.dir, len_v(r.dir)).y + 1.0) * 0.5;
	return (sum_v(mul_n(vec(1.0, 1.0, 1.0), 1.0 - a), mul_n(vec(0.5, 0.7, 1.0), a)));
}

int	vec_to_colour(t_vec v)
{
	return ((int)(v.x * 255.0) << 16 | (int)(v.y * 255.0) << 8 | (int)(v.z * 255.0));
}
