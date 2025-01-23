/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:55:00 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/23 10:39:42 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>

#define WIDTH	800
#define HEIGHT	600

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef t_vec	t_point;
typedef t_vec	t_colour;

typedef struct s_ray
{
	t_point	origin;
	t_vec	dir;
}	t_ray;

typedef struct s_camera
{
	double	window_width;
	double	window_height;
	double	aspect_ratio;

	double	viewport_width;
	double	viewport_height;
	double	focal_length;

	t_point	center;
	t_vec	viewport_u;
	t_vec	viewport_v;
	t_vec	delta_u;
	t_vec	delta_v;
	t_point	viewport_ulp;
	t_point	pixel_zero;
}	t_camera;

// camera.c
void		camera_init(t_camera *c);
t_colour	ray_colour(t_ray r);
int			vec_to_colour(t_vec v);

// raytracing.h
double		sphere_hit(t_ray ray, t_point center, double r);

// vector_math.c
t_vec		vec(double x, double y, double z);
t_vec		sub_n(t_vec v, double n);
t_vec		sum_n(t_vec v, double n);
t_vec		div_n(t_vec v, double n);
t_vec		mul_n(t_vec v, double n);
t_vec		sub_v(t_vec v1, t_vec v2);
t_vec		sum_v(t_vec v1, t_vec v2);
t_vec		div_v(t_vec v1, t_vec v2);
t_vec		mul_v(t_vec v1, t_vec v2);
double		dot(t_vec v1, t_vec v2);
double		len_v(t_vec v);
double		len_v_squared(t_vec v);
t_vec		unit_v(t_vec v);
t_ray		ray(t_point origin, t_vec dir);
t_point		at(t_ray r, double t);
