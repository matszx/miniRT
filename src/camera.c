/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:45:25 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/19 15:43:40 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

int	vec_to_colour(t_vec v)
{
	int res = ((int)v.x << 16 | (int)v.y << 8 | (int)v.z);
	(void)res;
	return (255);
}

t_vec	ray_colour(t_ray r)
{
	t_vec	unit_v;
	int		a;
	t_vec	res;

	unit_v = v_divd(r.dir, v_len(r.dir));
	a = (unit_v.y + 1.0) * 0.5;
	res = v_sum(v_muld(vec(1.0, 1.0, 1.0), 1.0 - a), v_muld(vec(0.55, 0.7, 1.0), a));
	return (res);
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
	c->delta_v = v_divd(c->viewport_v, c->window_height);
	c->delta_u = v_divd(c->viewport_u, c->window_width);
	c->viewport_ulp = v_diff(v_diff(v_diff(c->center, v_divd(c->viewport_v, 2)), v_divd(c->viewport_u, 2)), vec(0.0, 0.0, c->focal_length));
	c->pixel_zero = v_sum(c->viewport_ulp, v_muld(v_sum(c->delta_v, c->delta_u), 0.5));
}
