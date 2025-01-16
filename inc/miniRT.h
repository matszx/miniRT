/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:55:00 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/16 20:08:23 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "parse.h"
#include "render.h"

#define WIDTH	600	// window width
#define HEIGHT	600	// window height

typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

void	ft_pxl_put(t_img *img, int x, int y, int colour);
