/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:54:20 by mcygan            #+#    #+#             */
/*   Updated: 2025/01/17 13:38:43 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

void	ft_pxl_put(t_img *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->pxl_ptr + (x * img->bpp / 8) + (y * img->line_len);
	*(unsigned int *)dst = colour;
}
