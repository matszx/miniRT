/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:45:25 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/20 10:44:04 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

int	vec_to_colour(t_vec v)
{
	return ((int)(v.x * 255.0) << 16 | (int)(v.y * 255.0) << 8 | (int)(v.z * 255.0));
}

t_colour	ray_colour(t_ray r)
{
	double	a;

	a = (div_n(r.dir, len_v(r.dir)).y + 1.0) * 0.5;
	return (sum_v(mul_n(vec(1.0, 1.0, 1.0), 1.0 - a), mul_n(vec(0.5, 0.7, 1.0), a)));
}

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
