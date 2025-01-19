/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:05:52 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/19 15:44:21 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

int	main(void)
{
	void		*mlx;
	void		*window;
	t_camera	c;
	int			i;
	int			j;
	t_vec		pixel_center;
	t_vec		ray_dir;
	t_vec		pixel_colour;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WIDTH, HEIGHT, "miniRT");
	camera_init(&c);
	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			pixel_center = v_sum(c.pixel_zero, v_sum(v_muld(c.delta_v, i), v_muld(c.delta_u, j)));
			ray_dir = v_diff(pixel_center, c.center);
			pixel_colour = ray_colour(ray(c.center, ray_dir));
			mlx_pixel_put(mlx, window, j, i, vec_to_colour(pixel_colour));
		}
	}
	// printf("%d\n", i * j);
	mlx_loop(mlx);
	return (0);
}
