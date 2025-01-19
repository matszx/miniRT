/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:55:00 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/19 22:38:15 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
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
int			vec_to_colour(t_vec v);
t_vec		ray_colour(t_ray r);
void		camera_init(t_camera *c);

// vector_math.c
t_vec		vec(double x, double y, double z);
t_ray		ray(t_point origin, t_vec dir);
t_vec		sub_n(t_vec v, double n);
t_vec		sum_n(t_vec v, double n);
t_vec		div_n(t_vec v, double n);
t_vec		mul_n(t_vec v, double n);
t_vec		sub_v(t_vec v1, t_vec v2);
t_vec		sum_v(t_vec v1, t_vec v2);
t_vec		div_v(t_vec v1, t_vec v2);
t_vec		mul_v(t_vec v1, t_vec v2);
double		scalar(t_vec v1, t_vec v2);
double		len_v(t_vec v);
