/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:55:00 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/19 15:43:49 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT	600
#define WIDTH	800

typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec, t_point;

typedef struct s_ray
{
	t_point	origin;
	t_vec	dir;
}	t_ray;

typedef struct s_camera
{
	t_img	img;

	double	window_width;
	double	window_height;
	double	aspect_ratio;

	double	viewport_width;
	double	viewport_height;
	double	focal_length;

	t_vec	center;
	t_vec	viewport_u;
	t_vec	viewport_v;
	t_vec	delta_u;
	t_vec	delta_v;
	t_vec	viewport_ulp;
	t_vec	pixel_zero;
}	t_camera;

t_vec		vec(double x, double y, double z);
t_vec		v_diff(t_vec v1, t_vec v2);
t_vec		v_sum(t_vec v1, t_vec v2);
t_vec		v_div(t_vec v1, t_vec v2);
t_vec		v_mul(t_vec v1, t_vec v2);

t_vec		v_diffd(t_vec v1, double n);
t_vec		v_sumd(t_vec v1, double n);
t_vec		v_divd(t_vec v1, double n);
t_vec		v_muld(t_vec v1, double n);

double		v_dot(t_vec v1, t_vec v2);
double		v_len(t_vec v);
t_ray		ray(t_point origin, t_vec dir);

int			vec_to_colour(t_vec v);
t_vec		ray_colour(t_ray r);
void		camera_init(t_camera *c);
