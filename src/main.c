/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:05:52 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/19 21:54:02 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

static void	render_scene(void *mlx, void *win, t_camera *c)
{
	int			i;
	int			j;
	t_point		p_center;
	t_vec		ray_dir;
	t_colour		p_col;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			p_center = sum_v(c->pixel_zero, sum_v(mul_n(c->delta_v, i), mul_n(c->delta_u, j)));
			ray_dir = sub_v(p_center, c->center);
			p_col = ray_colour(ray(c->center, ray_dir));
			mlx_pixel_put(mlx, win, j, i, vec_to_colour(p_col));
		}
	}
}

int	main(void)
{
	void		*mlx;
	void		*window;
	t_camera	camera;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WIDTH, HEIGHT, "miniRT");
	camera_init(&camera);
	render_scene(mlx, window, &camera);
	mlx_loop(mlx);
	return (0);
}
